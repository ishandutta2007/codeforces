//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo aa[101][101];
llo ans[101][101];
llo vis[101][101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		vector<pair<llo,pair<llo,llo>>> ss2;
		for(llo i=0;i<n;i++){
			for(llo j=0;j<m;j++){
				cin>>aa[i][j];
				ss2.pb({aa[i][j],{i,j}});
			}
		}
		sort(ss2.begin(),ss2.end());
		vector<pair<pair<llo,llo>,llo>> ss;
		for(auto j:ss2){
			ss.pb({j.b,j.a});
		}
		for(llo i=0;i<n;i++){
			for(llo j=0;j<m;j++){
				vis[i][j]=0;
			}
		}
		for(llo i=0;i<m;i++){
			vis[ss[i].a.a][ss[i].a.b]=1;
		}
		for(llo i=0;i<m;i++){
			ans[ss[i].a.a][i]=ss[i].b;
			for(llo j=0;j<n;j++){
				if(j==ss[i].a.a){
					continue;
				}
				for(llo k=0;k<m;k++){
					if(vis[j][k]==0){
						vis[j][k]=1;
						ans[j][i]=aa[j][k];
						break;
					}
				}
			}
		}
		for(llo i=0;i<n;i++){
			for(llo j=0;j<m;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
		



	}



 
 
	return 0;
}