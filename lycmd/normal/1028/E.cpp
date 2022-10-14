#include<bits/stdc++.h>
#define ord(x) ((x)?(x):n)
#define int long long
using namespace std;
int const N=233333;
int n,a[N],b[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i];
	a[0]=b[0]=b[n];
	int flg=1,mx=a[0],p=0;
	for(int i=1;i<=n;i++)
		mx=max(mx,a[i]),flg&=a[i]==a[0];
	for(int i=1;i<=n;i++)
		if(a[i]==mx&&a[i-1]<mx)p=i;
	if(flg){
		if(a[0])
			cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(int i=1;i<=n;i++)
				cout<<"1 ";
		}
		return 0;
	}
	a[ord((p-1+n)%n)]+=mx;
	for(int i=1;i<n;i++)
		a[ord((p-i+n)%n)]+=a[ord((p-i+1+n)%n)];
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
}