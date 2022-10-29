#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 210000;

int n;
int a[maxn],b[maxn];
char str[maxn],ss[5];

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	cin>>(str+1);
	
	int L=1,U=0;
	for(int i=1;i<=n;i++)
	{
		if(str[i]!=str[i-1]) b[i]=++U;
		else b[i]=--L;
	}
	
	ss[0]=str[n]; ss[1]=str[n]=='L'?'R':'L';
	for(int i=1;i<=n;i++)
	{
		cout<<a[b[i]-L+1]<<' '<<ss[(U-b[i])%2]<<endl;
	}
	
	return 0;
}