#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo aa[100001];
vector<llo> pre[100001];
llo cur[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;

		for(llo i=0;i<n;i++){
			cin>>aa[i];
			set<llo> xx;
			for(llo j=1;j<=k;j++){
				xx.insert(aa[i]/j);
				/*if((aa[i]/j)<=k){
					xx.pb(j);
				}
				if(j<=k){
					xx.pb(aa[i]/j);
				}*/
			}
			for(auto j:xx){
				pre[j].pb(i);
				//cout<<j<<",";
			}
		//	cout<<endl;
		}
		set<pair<llo,llo>> ss;
		for(llo i=0;i<n;i++){
			cur[i]=-1;
		}
		llo ans=3000;
		for(llo j=3000;j>=1;j--){
			if(pre[j].size()){
				for(auto i:pre[j]){
					if(cur[i]>=0){
						ss.erase({cur[i],i});
					}
					cur[i]=j;
					ss.insert({cur[i],i});
				}
				if(ss.size()==n){
					auto ii=ss.end();
					ii--;
					ans=min(ans,(*ii).a-j);
				}
				pre[j].clear();
			}
		}

		cout<<ans<<endl;


	}






	return 0;
}