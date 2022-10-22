#include <stdio.h>
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

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
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001
int n,m;
vector<int> u,v,w;

vector<int> get(int x){
	vector<pair<int,int>> t(m);
	
	rep(i,m){
		t[i] = make_pair(abs(w[i]-x), i);
	}
	sort(t.begin(),t.end());
	vector<int> ret(t.size());
	rep(i,t.size())ret[i] = t[i].second;
	return ret;
}

int main(){
	cin>>n>>m;
	u.resize(m);
	v.resize(m);
	w.resize(m);
	
	rep(i,m){
		cin>>u[i]>>v[i]>>w[i];
		u[i]--,v[i]--;
	}
	
	vector<int> l(1,-Inf);
	l.push_back(Inf);
	rep(i,m){
		l.push_back(w[i]);
		for(int j=i+1;j<m;j++){
			l.push_back((w[i]+w[j])/2 + 1);
		}
	}
	sort(l.begin(),l.end());
	l.erase(unique(l.begin(),l.end()),l.end());
	//cout<<'a'<<endl;
	vector<long long> A(l.size()),B(l.size());
	array<int,4> tmp;
	rep(i,l.size()){
		//cout<<l[i]<<endl;
		vector<array<int,4>> a;
		rep(j,m){
			tmp[3] = j;
			tmp[0] = abs(l[i] - w[j]);
			if(l[i] < w[j]){
				tmp[1] = -1;
				tmp[2] = w[j];
			}
			else{
				tmp[1] = 1;
				tmp[2] = -w[j];
			}
			a.push_back(tmp);
		}
		//cout<<'a'<<endl;
		sort(a.begin(),a.end());
		
		dsu D(n);
		rep(j,m){
			int ind = a[j][3];
			if(D.same(u[ind],v[ind]))continue;
			D.merge(u[ind],v[ind]);
			A[i] += a[j][1];
			B[i] += a[j][2];
		}
	}
	
	
	long long p,k,a,b,c;
	cin>>p>>k>>a>>b>>c;
	vector<long long> q(k);
	rep(i,p)scanf("%lld",&q[i]);
	
	for(int i=p;i<k;i++){
		q[i] = (q[i-1] * a + b)%c;
	}
	sort(q.begin(),q.end());
	
	long long ans = 0LL;
	int cur = 0;
	rep(i,k){
		while(!(l[cur]<=q[i]&&q[i]<l[cur+1]))cur++;
		long long temp = A[cur] * q[i];
		temp += B[cur];
		ans ^= temp;
	}
	cout<<ans<<endl;
	
	return 0;
}