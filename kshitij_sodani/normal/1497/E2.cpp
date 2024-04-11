//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


llo t;
llo n,k;
int it[200001];
int dp[200001][21];
bool vis[5000];

int cur[10000001];
int re[200001];
/*vector<llo> pre[10000001];*/
/*pair<pair<llo,llo>,pair<llo,llo>> dp[5001][2][2];
pair<llo,llo> cur[5001][2][2];*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	vector<llo> xx;
	for(llo i=2;i<=3200;i++){
		if(vis[i]==0){
			xx.pb(i*i);
			for(llo j=i;j<=3200;j+=i){
				vis[j]=1;
			}
		}
	}
	//return 0;
	while(t--){
		cin>>n>>k;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			for(auto j:xx){
				while(it[i]%j==0){
					it[i]/=j;
				}
			}
			/*llo cur2=it[i];
			while(cur2>1){
				llo st=-1;
				for(llo j=2;j*j<=cur2;j++){
					if(cur2%j==0){
						st=j;
						break;
					}
				}
				if(st==-1){
					break;
				}
				int co=0;
				while(cur2%st==0){
					cur2/=st;
					co++;
				}
				co=co-(co%2);
				for(int j=0;j<co;j++){
					it[i]/=st;
				}

			}*/

			if(cur[it[i]]>0){
				re[i]=cur[it[i]]-1;
			}
			else{
				re[i]=-1;
			}
			cur[it[i]]=i+1;
		//	cout<<it[i]<<",";
		}
		//cout<<endl;
		set<llo> ss;
		vector<llo> aa;
		for(llo i=0;i<n;i++){
			if(re[i]>=0){
				ss.insert(-re[i]);
			}
			aa.clear();
			
			auto jj=ss.begin();
			for(llo ii=0;ii<k+1;ii++){
				if(jj==ss.end()){
					break;
				}
				aa.pb(-(*jj));
				jj++;
			}



			for(llo j=0;j<=k;j++){
				dp[i][j]=n;
				if(aa.size()<=k){
					if(aa.size()<=j){
						dp[i][j]=1;
					}
				}
				for(llo ii=0;ii<aa.size();ii++){
					if(j>=ii){
						dp[i][j]=min(dp[i][j],dp[aa[ii]][j-ii]+1);
					}
				}
			}
		}
		cout<<dp[n-1][k]<<endl;
		for(llo i=0;i<n;i++){
			cur[it[i]]=0;
		}
	}







	return 0;
}