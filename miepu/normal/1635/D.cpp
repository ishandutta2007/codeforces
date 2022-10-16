#include<bits/stdc++.h>
#define int long long
const int M=1000005,mod=1e9+7;
using namespace std;

int n,p;
int a[M];
int f[M];
map<int,int> vis;


void solve(){
	cin>>n>>p;
	f[0]=1,f[1]=1;
	for(int i=2;i<=p;i++)	
		f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=1;i<=p;i++)
		f[i]=(f[i]+f[i-1])%mod;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		int fl=0;
		for(int k=a[i];k;){
			if(vis[k])fl=1;
			if(k&1){
				k>>=1;
			}
			else{
				if(k%4)break;
				k/=4;
			}
		}
		if(fl)continue;
		vis[a[i]]=1;
		int nw=0;
		while(a[i])nw++,a[i]>>=1;
		if(p<nw)continue;
		ans+=f[p-nw];
	}
	cout<<ans%mod<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}