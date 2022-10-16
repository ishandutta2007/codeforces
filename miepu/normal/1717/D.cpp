#include<bits/stdc++.h>
#define int long long
const int N=500005,mod=1e9+7;
using namespace std;

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

void solve(){
	int n,k;cin>>n>>k;
	init();
//	int nw=gsc(2,n-1);
	int res=0;
	for(int i=0;i<=k&&i<=n;i++){
		res+=C(n,i);
	}
	cout<<res%mod<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}