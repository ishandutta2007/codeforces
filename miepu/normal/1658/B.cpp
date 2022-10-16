#include<bits/stdc++.h>
#define int long long
const int N=1000050,mod=998244353;
using namespace std;

int jc[N],ij[N],iv[N]; 
int C(int n,int m){
    if(n<m)return 0;
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
	int n;cin>>n;
	if(n&1){
		cout<<0<<endl;
	}else cout<<jc[n/2]*jc[n/2]%mod<<endl;
}

main(){
	ios::sync_with_stdio(false);
	init();
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}