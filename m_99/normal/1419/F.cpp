#include <stdio.h>
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000005

int main(){

	int n;
	cin>>n;
	vector<int> vx,vy;
	vector<int> x(n),y(n);
	rep(i,n){
		scanf("%d %d",&x[i],&y[i]);
		vx.push_back(x[i]);
		vy.push_back(y[i]);
	}
	
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	
	vector<vector<pair<int,int>>> mx(n,vector<pair<int,int>>()),my(n,vector<pair<int,int>>());
	
	rep(i,n){
		mx[distance(vx.begin(),lower_bound(vx.begin(),vx.end(),x[i]))].emplace_back(y[i],i);
		my[distance(vy.begin(),lower_bound(vy.begin(),vy.end(),y[i]))].emplace_back(x[i],i);
	}
	
	for(auto &a:mx){
		sort(a.begin(),a.end());
	}
	for(auto &a:my){
		sort(a.begin(),a.end());
	}
	
	vector L(n,vector (n,vector<int>()));
	
	rep(i,n){
		rep(j,n){
			int X = x[i],Y = y[j];
			{
				pair<int,int> p(Y,Inf);
				vector<pair<int,int>> &temp = mx[distance(vx.begin(),lower_bound(vx.begin(),vx.end(),X))];
				auto it = upper_bound(temp.begin(),temp.end(),p);
				if(it!=temp.end())L[i][j].push_back(it->second);
				if(it!=temp.begin()){
					it--;
					L[i][j].push_back(it->second);
				}
			}
			{
				pair<int,int> p(X,Inf);
				vector<pair<int,int>> &temp = my[distance(vy.begin(),lower_bound(vy.begin(),vy.end(),Y))];
				auto it = upper_bound(temp.begin(),temp.end(),p);
				if(it!=temp.end())L[i][j].push_back(it->second);
				if(it!=temp.begin()){
					it--;
					L[i][j].push_back(it->second);
				}
			}
			
		}
	}
	
	vector<long long> dis;
	rep(i,n){
		for(int j=i+1;j<n;j++){
			dis.push_back(abs(x[i]-x[j]));
			dis.push_back(abs(y[i]-y[j]));
			if(x[i]==x[j]){
				dis.push_back((abs(y[i]-y[j])+1)/2);

			}
			if(y[i]==y[j]){
				dis.push_back((abs(x[i]-x[j])+1)/2);
			}
		}
	}
	
	sort(dis.begin(),dis.end());
	dis.erase(unique(dis.begin(),dis.end()),dis.end());
	
	long long ng = -1,ok = dis.size();
	
	while(ok-ng>1){
		long long mid = (ok+ng)/2;

		dsu D(n);
		rep(i,n){
			for(int j=i+1;j<n;j++){
				if(x[i]==x[j]){
					if(abs(y[i]-y[j])<=dis[mid])D.merge(i,j);
				}
				if(y[i]==y[j]){
					if(abs(x[i]-x[j])<=dis[mid])D.merge(i,j);
				}
			}
		}
		
		vector<int> P;
		rep(i,n){
			if(D.leader(i)==i)P.push_back(i);
		}
		if(P.size()>=5){
			ng = mid;
			continue;
		}
		if(P.size()==1){
			ok = mid;
			continue;
		}
		bool f = false;
		
		if(P.size()==2){
			rep(i,n){
				for(int j=i+1;j<n;j++){
					if(D.leader(i)==D.leader(j))continue;
					if(x[i]==x[j]){
						if(abs(y[i]-y[j])<=dis[mid]*2)f = true;
					}
					if(y[i]==y[j]){
						if(abs(x[i]-x[j])<=dis[mid]*2)f=true;
					}
					if(f)break;
				}
				if(f)break;
			}
		}
		
		if(f){
			ok = mid;
			continue;
		}
		
		rep(i,n){
			rep(j,n){
				dsu DD(P.size()+1);
				rep(k,L[i][j].size()){
					if(abs(x[i]-x[L[i][j][k]]) + abs(y[j] - y[L[i][j][k]]) <= dis[mid]){
						int LL = D.leader(L[i][j][k]);
						int ind = P.size();
						rep(l,P.size()){
							if(LL == P[l]){
								ind = l;
								break;
							}
						}
						DD.merge(P.size(),ind);
					}
				}
				if(DD.size(0)==P.size()+1){
					f=true;
					break;
				}
			}
			if(f)break;
		}
		
		
		
		if(f)ok = mid;
		else ng = mid;
		
	}
	if(ok==dis.size())cout<<-1<<endl;
	else cout<<dis[ok]<<endl;

	return 0;
}