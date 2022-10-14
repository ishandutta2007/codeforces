#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,a[N],b[N],a1[N],b1[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<n;i++)
		a1[i]=a[i+1]-a[i],b1[i]=b[i+1]-b[i];
	sort(a1+1,a1+n);
	sort(b1+1,b1+n);
	int flg=a[1]==b[1]&&a[n]==b[n];
	for(int i=1;i<n&&flg;i++)
		flg&=a1[i]==b1[i];
	cout<<(flg?"Yes\n":"No\n");
}