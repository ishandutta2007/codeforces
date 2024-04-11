#include<bits/stdc++.h>
#define int long long
const int N=1000005,mod=998244353;
using namespace std;

int n,k;
int a[N]; 

int jc[N],ij[N],iv[N]; 
int A(int n,int m){
    if(n<m||n<0||m<0)return 0;
    return jc[n]*ij[n-m]%mod;
}
void init(){
    iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
}

void solve(){
	cin>>n>>k; 
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	for(int i=n;i>n-k;i--)
		if(a[i]>0){
			cout<<0<<'\n';
			return ;
		}
	int res=1;
	for(int i=1;i<=k;i++){
		res=res*i%mod;
	}
	for(int i=1;i<=n-k;i++){
		if(a[i]==0)res=res*(k+1)%mod;
		if(a[i]==-1)res=res*(k+i)%mod;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}