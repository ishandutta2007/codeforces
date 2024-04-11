//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
//llo it[1001];
vector<pair<llo,llo>> pre[200002];
vector<llo> mi[200002];
llo dp[200002];//next is type 2
llo dp2[200002];//next is type 1
llo vis[301];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		vector<pair<llo,llo>> aa;
		for(llo i=0;i<n*m;i++){
			llo x;
			cin>>x;
			aa.pb({x,i});
		}
		llo ans=0;
		sort(aa.begin(),aa.end());
		for(llo i=0;i<n*m;i+=m){
			vector<pair<llo,llo>> bb;
			for(llo j=i;j<i+m;j++){
				bb.pb({aa[j].a,-aa[j].b});
			}
			sort(bb.begin(),bb.end());
			vector<pair<llo,llo>> cc;
			for(llo j=0;j<m;j++){
				bb[j].b=-bb[j].b;
				cc.pb({bb[j].b,j});
				vis[j]=0;
			}
			sort(cc.begin(),cc.end());
			for(auto j:cc){
				for(llo k=0;k<j.b;k++){
					ans+=vis[k];
				}
				vis[j.b]=1;
			}


		}
		cout<<ans<<endl;

	}


 
 
 
	return 0;
}