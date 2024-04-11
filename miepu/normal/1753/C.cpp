#include<bits/stdc++.h>
#define int long long
const int N=1000005,mod=998244353;
using namespace std;

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

int n,a[N];

void solve(){
	cin>>n;
	int c0=0,c1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c0+=a[i]==0;
		c1+=a[i]==1;
	}
	int er=0;
	for(int i=1;i<=c0;i++)er+=a[i];
	int res=0;
	for(int i=1;i<=er;i++)
		res+=n*(n-1)/2%mod*inv(i*i)%mod;
	cout<<res%mod<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}