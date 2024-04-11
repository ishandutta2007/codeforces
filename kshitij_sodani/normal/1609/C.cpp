//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo pre[1000001];
vector<llo> aa[200001];
llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	pre[1]=0;
	for(llo i=2;i<=1000000;i++){
		if(pre[i]==0){
			for(llo j=i;j<=1000000;j+=i){
				pre[j]=2;
			}
			pre[i]=1;
		}
	}
	while(t--){
		llo n,e;
		cin>>n>>e;
		for(llo i=0;i<e;i++){
			aa[i].clear();
		}
		for(llo i=0;i<n;i++){
			cin>>it[i];
			aa[i%e].pb(pre[it[i]]);
		}
		llo ans=0;
		for(llo i=0;i<e;i++){
			map<llo,llo> ss;
			llo co=0;
			for(llo j=0;j<aa[i].size();j++){
				if(j>=1){
					ss[co-aa[i][j-1]]++;
				}
				co+=aa[i][j];
				if(ss.find(co-1)!=ss.end()){
					ans+=ss[co-1];
				}
			}
		}
		cout<<ans<<endl;
	}




 
	return 0;
}