#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){	
	
	int _t;
	cin>>_t;
	
	
	for(int _=1;_<=_t;_++){
		
		int n;
		scanf("%d",&n);
		
		vector<int> a(n),b(n),m(n);
		map<int,vector<int>> mp;
		rep(i,n){
			scanf("%d %d %d",&a[i],&b[i],&m[i]);
			mp[a[i]+b[i]-m[i]].push_back(i);
		}
		vector<int> x(n),y(n);
		int ans = 0;
		for(auto t:mp){
			vector<pair<pair<int,int>,int>> p;
			rep(i,t.second.size()){
				int ind = t.second[i];
				int l = max(0,a[ind]-m[ind]);
				int r = min(a[ind], a[ind] - (m[ind]-b[ind]));
				p.emplace_back(make_pair(r,l),ind);
			}
			sort(p.begin(),p.end());
			vector<int> temp;
			set<int> S;
			rep(i,p.size()){
				int ind = p[i].second;
				int l = p[i].first.second;
				int r = p[i].first.first;
				auto it = S.lower_bound(l);
				if(it==S.end()||(*it)>r){
					S.insert(r);
					x[ind] = a[ind] - r;
					y[ind] = m[ind] - x[ind];
					ans++;
					continue;
				}
				
				x[ind] = a[ind] - (*it);
				y[ind]  =m[ind]  - x[ind];
			}
			
			
		}
		printf("%d\n",ans);
		rep(i,n)printf("%d %d\n",x[i],y[i]);
		
	}
	
	return 0;
	
}