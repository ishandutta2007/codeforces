#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll a[105],b[105];
ll phi(ll n){
	ll i; int cnt=0;
	for (i=2; i*i<=n; i++) if (n%i==0){
		cnt++; a[cnt]=i;b[cnt]=0;
		while (n%i==0){ b[cnt]++;n/=i;}
	}
	if (n>1){
		a[++cnt]=n; b[cnt]=1;
	}
	ll tmp=1;
	for (int k=1; k<=cnt; k++){
		tmp*=a[k]-1;
		for(b[k]--;b[k]>0;b[k]--)tmp*=a[k];
	}
	return tmp;
}
int main(){
	ll n,m;cin>>n>>m;
	n=phi(n);
	for (ll i=2; i<=m; i++){
		if (n==1){puts("1"); return 0;
		}
		if (i&1) n=phi(n);
	}cout<<n%mod<<endl;
}