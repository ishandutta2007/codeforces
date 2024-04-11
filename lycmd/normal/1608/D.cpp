#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333,MOD=998244353;
int x,y,k,n,ans,fac[N],inv[N];
string s[N];
inline int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
inline int C(int n,int m){
	return m<0||n<m?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=0;i<N;i++)
		fac[i]=i?fac[i-1]*i%MOD:1;
	inv[N-1]=qpow(fac[N-1],MOD-2);
	for(int i=N-1;i;i--)
		inv[i-1]=inv[i]*i%MOD; 
	cin>>n;
	int flg1=0,flg2=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i][0]==s[i][1]){
			switch(s[i][0]){
				case'?':x+=2,y++,k++;break;
				case'W':y--,flg1=1;break;
				case'B':y++,flg1=1;break;
			}
		}else{
			switch(s[i][0]^s[i][1]^'?'){
				case'W':x++;break;
				case'B':x++,y++;break;
			}
		}
	}
	ans=C(x,y);
	if(!ans||flg1)
		cout<<ans<<"\n",exit(0);
	ans=(ans-qpow(2,k)+MOD)%MOD;
	flg1=1;
	for(int i=1;i<=n;i++)
		flg1&=s[i][0]^'B'&&s[i][1]^'W',
		flg2&=s[i][0]^'W'&&s[i][1]^'B';
	cout<<(ans+flg1+flg2)%MOD<<"\n"; 
}