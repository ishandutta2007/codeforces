#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=3010;
int n,k,ans,a[N],s[N],c[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i],c[i]=c[i-1]+!a[i];
	if(abs(s[n])-k*c[n]>0)
		cout<<"-1\n",exit(0);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			int ts=s[j]-s[i-1],ts1=s[n]-ts,tc=c[j]-c[i-1],tc1=c[n]-tc;
			ans=max(ans,max(min(abs(ts+tc*k),abs(ts1-tc1*k)),
				min(abs(ts-tc*k),abs(ts1+tc1*k)))+1);
		}
	cout<<ans<<"\n"; 
}