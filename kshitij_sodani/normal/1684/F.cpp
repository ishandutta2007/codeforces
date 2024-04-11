#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo t;
llo it[200001];
set<llo> pre[200001];
vector<llo> cc[200001];
vector<llo> dd[200001];
vector<llo> ee[200001];
vector<llo> ff[200001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		map<llo,llo> ss;
		for(llo i=0;i<n;i++){
			pre[i].clear();
			cc[i].clear();
			dd[i].clear();
			ee[i].clear();
			ff[i].clear();
		}
		for(llo i=0;i<n;i++){
			cin>>it[i];
			ss[it[i]]++;
		}
		llo ind=1;
		map<llo,llo> tt;
		for(auto j:ss){
			tt[j.a]=ind;
			ind++;
		}
		for(llo i=0;i<n;i++){
			it[i]=tt[it[i]];
			pre[it[i]].insert(i);
		}
		for(llo j=0;j<m;j++){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			if(aa==bb){
				continue;
			}
			cc[aa].pb(bb);
			dd[bb].pb(aa);
		}
		multiset<llo> cur;
		vector<pair<llo,llo>> dd2;
		for(llo i=0;i<n;i++){
			for(auto j:cc[i]){
				cur.insert(j);
			}
			llo ind=i;
			if(cur.size()){
				auto j=cur.end();
				j--;
				ind=(*j);
			}
			if(ind>i){
				auto jj=pre[it[i]].lower_bound(i+1);
				if(jj!=pre[it[i]].end()){
					if((*jj)<=ind){
						dd2.pb({i,(*jj)});
					}
				}
				 jj=pre[it[i]].lower_bound(ind+1);
				if(jj!=pre[it[i]].begin()){
					jj--;
					if((*jj)>i){
						dd2.pb({i,(*jj)});
					}
				}
			}
			for(auto j:dd[i]){
				auto jj=cur.find(i);
				cur.erase(jj);
			}
		}
		if(dd2.size()==0){
			cout<<0<<endl;
			continue;
		}
		llo re=-1;
		for(auto j:dd2){
			re=max(re,j.a);
		}
		llo st=1;
		for(auto j:dd2){
			ee[j.a].pb(j.b);
			ff[j.b].pb(j.a);
			//cout<<j.a<<","<<j.b<<endl;
		}
		llo ans=n;
		for(llo i=0;i<n;i++){
		
			ans=min(ans,re-i+1);
			if(ff[i].size()){
				break;
			}
			for(auto j:ee[i]){
				re=max(re,j);
			}
		}
		cout<<ans<<endl;
	}


	







	return 0;
}