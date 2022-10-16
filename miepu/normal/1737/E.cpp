#include<bits/stdc++.h>
#define int long long
const int N=1000005,mod=1e9+7;
using namespace std;

int f[N],g[N];
int pw[N],dl[N];

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

int jc[N],ij[N],iv[N]; 
int C(int n,int m){
    if(n<m||n<0||m<0)return 0;
    return jc[n]*ij[m]%mod*ij[n-m]%mod;
}
void init(){
    iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
}

void add(int&x,int y){
	x+=y;x%=mod;
}

void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)g[i]=dl[i]=0;
	int s=0;
	for(int i=n;i;i--){
		add(s,dl[i]);
		g[i]=i==n?1:s;
		add(s,g[i]);
		add(dl[i/2],mod-g[i]*gsc(iv[2],i-i/2)%mod);
		s=s*iv[2]%mod;
	}
	for(int i=1;i<=n;i++){
		cout<<gsc(iv[2],(i-1)/2)*g[i]%mod<<'\n';
	}
}

main(){
	init();
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}