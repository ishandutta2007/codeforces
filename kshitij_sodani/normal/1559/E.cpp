//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

const int mod=998244353;
int val[100001];
int ll[100001];
int rr[100001];
int dp[51][100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
	//	int ll,rr;
		cin>>ll[i]>>rr[i];
	}

	for(int i=m;i>=1;i--){
		int su=0;
		int st=1;
		vector<int> ss;
		for(int j=0;j<n;j++){
			int x=(ll[j]-1)/i;
			x++;
			x*=i;
			su+=x;
			if(su>m){
				st=0;
				break;
			}
			if(x>rr[j]){
				st=0;
				continue;
			}
			ss.pb((rr[j]-x)/i);
		}
		if(st==0){
			continue;
		}
	//	cout<<i<<":"<<endl;

		
		int le=(m-su)/i;
		for(int j=0;j<=n;j++){
			for(int k=0;k<=le;k++){
				dp[j][k]=0;
			}
			if(j==0){
				dp[0][0]=1;
			}
			else{
				for(int k=0;k<=le;k++){
					dp[j][k]+=dp[j-1][k];
					if(dp[j][k]>=mod){
							dp[j][k]-=mod;
						}
					if(ss[j-1]<k){
						dp[j][k]=dp[j][k]-dp[j-1][k-ss[j-1]-1]+mod;
						if(dp[j][k]>=mod){
							dp[j][k]-=mod;
						}
					}
				}
			}
			/*for(int k=0;k<=le;k++){
				cout<<dp[j][k]<<".";
			}
			cout<<endl;
*/
			for(int k=1;k<=le;k++){
				dp[j][k]+=dp[j][k-1];
				if(dp[j][k]>=mod){
					dp[j][k]-=mod;
				}
			}

		}
	/*	for(auto j:ss){
			cout<<j<<",";
		}
		cout<<endl;
		cout<<le<<"::"<<endl;*/
		val[i]=dp[ss.size()][le];
		//dp[0][0]=1;

		for(int j=2*i;j<=m;j+=i){
			val[i]=(val[i]-val[j]+mod);
			if(val[i]>=mod){
				val[i]-=mod;
			}
		}
	}
	/*for(int j=1;j<=m;j++){
		cout<<val[j]<<",";
	}
	cout<<endl;*/
	cout<<val[1]<<endl;
	
 
 
	return 0;
}