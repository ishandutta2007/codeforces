#include<bits/stdc++.h>
#define inf 10000000000
#define int long long
#define output(x); cout<<x<<endl;fflush(stdout);
using namespace std;
int a[4];
signed main()
{
	cin>>a[1]>>a[2]>>a[3];
	output("First");
	int s,k;
	s=a[1]+a[2]+a[3]+inf;
	output(inf);
	cin>>k;
	if(k==0)return 0;
	a[k]+=inf;
	output(a[k]*3-s);
	int kk;
	cin>>kk;
	if(kk==0)return 0;
	a[kk]+=a[k]*3-s;
	output(a[k]-a[1^2^3^k^kk]);
}