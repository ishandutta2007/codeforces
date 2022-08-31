//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
const int mod=31607;
int ee(int aa,int bb){
	if(bb==0){
		return 1;
	}
	int ac=ee(aa,bb/2);
	ac=(ac*ac)%mod;
	if(bb%2==1){
		ac=(ac*aa)%mod;
	}
	return ac;
}
int it[30][30];
int aa[30][30];
int dp[1<<21][21];
int pro[1<<21];

int val[1<<21];
int val2[1<<21];
int st[1<<21];
int cot[21];
int ans2[2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int ans=0;
	int xx=ee(10000,mod-2);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>it[i][j];
		//	it[i][j]=2;
			it[i][j]=(it[i][j]*xx)%mod;
		}
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((1<<j)&i){
				st[i]^=1;
				val2[i]=j;
			}
			else{
				val[i]=j;
			}
		}
	}
	for(int ii=0;ii<2;ii++){
		for(int jj=0;jj<2;jj++){
			int cur3=1;
			for(int i=0;i<n;i++){
				cot[i]=1;
				for(int j=0;j<n;j++){
					aa[i][j]=it[i][j];
					if(ii==1 and i==j){
						cur3=(cur3*aa[i][j])%mod;
						aa[i][j]=1;
					}
					else if(jj==1 and i+j==n-1){
						cur3=(cur3*aa[i][j])%mod;
						aa[i][j]=1;
					}
					cot[i]=(cot[i]*aa[i][j])%mod;
				}
			}
			/*for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<aa[i][j]<<",";
				}
				cout<<endl;
			}*/
			ans2[0]=0;
			ans2[1]=0;
			pro[0]=1;
			for(int i=1;i<(1<<n);i++){
				pro[i]=(pro[i-(1<<val2[i])]*cot[val2[i]])%mod;
			}
			for(int i=(1<<n)-1;i>=0;i--){
				int yy=(ii^jj)^st[i];
				if(i==(1<<n)-1){
					for(int j=0;j<n;j++){
						dp[i][j]=1;
					}
				}
				else{
					for(int j=0;j<n;j++){
						dp[i][j]=(dp[i+(1<<val[i])][j]*aa[val[i]][j])%mod;
					}
				}
				int cur=1;
				int cur2=0;
				for(int j=0;j<n;j++){
					int xx=cur2;
					cur2=(cur2+cur*dp[i][j])%mod;
					cur=(cur+xx*dp[i][j])%mod;
				}
				/*if(i==0 and ii==0 and jj==0){
					cur=(cur-1+mod)%mod;
				}*/
				ans2[yy]=(ans2[yy]+cur*pro[i])%mod;
				ans2[1-yy]=(ans2[1-yy]+cur2*pro[i])%mod;


			}

			if(ii==0 and jj==0){
				ans2[0]=(ans2[0]-1+mod)%mod;
			}

		//	cout<<ans2[1]<<":"<<ans2[0]<<endl;
			ans=(ans+ans2[1]*cur3)%mod;
			ans=(ans-((ans2[0]*cur3)%mod)+mod)%mod;
		}
	}
	cout<<ans<<endl;
 
 
 
 
 
 
 
	return 0;
}