#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

long long get(vector<int> x,vector<int> y,vector<int> L){
	int n = x.size();
	vector<pair<int,int>> p(n);
	rep(i,n){
		p[i] = make_pair(x[i],y[i]);
	}
	
	sort(p.begin(),p.end());
	int l = 0;
	long long ret = 0LL;
	map<int,int> mp;
	rep(i,n){
		//cout<<p[i].first<<','<<p[i].second<<endl;
		while(true){
			int d = distance(lower_bound(L.begin(),L.end(),p[l].first), lower_bound(L.begin(),L.end(),p[i].first));
			if(d!=0){
				mp[p[l].second]--;
				l++;
			}
			else break;
		}
		ret += i-l - mp[p[i].second];
		mp[p[i].second] ++;
	}
	//cout<<endl;
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		vector<int> x(n),y(m);
		rep(i,n)scanf("%d",&x[i]);
		rep(i,m)scanf("%d",&y[i]);
		
		vector<int> p(k),q(k);
		rep(i,k){
			scanf("%d %d",&p[i],&q[i]);
		}
		
		vector<int> x0,y0,x1,y1;
		
		rep(i,k){
			bool b0 = binary_search(x.begin(),x.end(),p[i]);
			bool b1 = binary_search(y.begin(),y.end(),q[i]);
			if(b0&&b1)continue;
			if(b0){
				x0.push_back(p[i]);
				y0.push_back(q[i]);
			}
			else{
				x1.push_back(p[i]);
				y1.push_back(q[i]);
			}
		}
		
		long long ans = 0LL;
		ans += get(y0,x0,y);
		ans += get(x1,y1,x);
		
		printf("%lld\n",ans);
		
	}
	
	return 0;
}