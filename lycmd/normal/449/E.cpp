#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010,MOD=1000000007,INV3=333333336;
int t,n,m,f,phi[N],ps[N],s1[N],s2[N],s3[N];
signed main(){
	ios::sync_with_stdio(0);
	for(int i=1;i<N;i++)
		phi[i]=i;
	for(int i=2;i<N;i++)
		if(phi[i]==i)
			for(int j=i;j<N;j+=i)
				phi[j]=phi[j]/i*(i-1);
	for(int i=1;i<N;i++)
		for(int j=i;j<N;j+=i)
			ps[j]=(ps[j]+j/i*phi[i])%MOD;
	for(int i=1;i<N;i++)
		f=(i*(i-1)%MOD*(2*i-1)%MOD*INV3-i*i%MOD+MOD+2*ps[i])%MOD,
		s1[i]=(s1[i-1]+f)%MOD,s2[i]=(s2[i-1]+i*f%MOD)%MOD,
		s3[i]=(s3[i-1]+i*i%MOD*f%MOD)%MOD;
	for(cin>>t;t--;){
		cin>>n>>m;
		if(n>m)swap(n,m);
		cout<<((1+n+m+n*m)%MOD*s1[n]%MOD-(n+m+2)*s2[n]%MOD+s3[n]+MOD)%MOD<<"\n";
	}
}