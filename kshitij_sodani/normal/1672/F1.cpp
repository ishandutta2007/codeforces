#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo it[200001];
llo co[200001];
vector<llo> pre[200001];
llo ans[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			co[i]=0;
			pre[i].clear();
		}
		vector<pair<llo,llo>> dd;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			it[i]--;
			co[it[i]]++;
			pre[it[i]].pb(i);
		}
		for(llo i=0;i<n;i++){
			dd.pb({co[i],i});
		}	
		sort(dd.begin(),dd.end());
		for(llo i=0;i<n;i++){
			ans[i]=it[i];
		}
		for(llo i=0;i<dd.size();i++){
			if(i+1==dd.size()){
				break;
			}
			llo x=pre[dd[i].b].size();
			for(llo j=0;j<x;j++){
				for(llo ii=i;ii<dd.size();ii++){
					llo ne;
					if(ii+1<dd.size()){
						ne=dd[ii+1].b;
					}
					else{
						ne=dd[i].b;
					}
					ans[pre[dd[ii].b].back()]=ne;
					pre[dd[ii].b].pop_back();
				}
			}
		}
		for(llo i=0;i<n;i++){
			cout<<ans[i]+1<<" ";
		}
		cout<<endl;


	}







	return 0;
}