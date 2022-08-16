#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;


const llo mod=998244353;
llo dp[200001];
llo dp2[200001];
llo su[200001];
llo ans[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0]=1;
	llo n,k;
	cin>>n>>k;
	llo su2=0;
	while(true){
		su2+=k;
		if(su2>n){
			break;
		}
		llo j=0;
		for(llo i=0;i<=n;i++){
			if(i>=k){
				su[j]+=dp[i-k];
				if(su[j]>=mod){
					su[j]-=mod;
				}
			}
			dp2[i]=su[j];
			j++;
			if(j==k){
				j=0;
			}
		}
		for(llo i=0;i<=n;i++){
			ans[i]+=dp2[i];
			if(ans[i]>=mod){
				ans[i]-=mod;
			}
			dp[i]=dp2[i];
			dp2[i]=0;
			su[i]=0;
		}
		k++;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;







	return 0;
}