#include<bits/stdc++.h>
using namespace std;int n,k,a1,a2,a3,a4,i=1;char c;
int main()
{
	cin>>n>>k;for (;i<=n && cin>>c;i++) if (c==48) a1=a1?a1:i,a2=i;else a3=a3?a3:i,a4=i;
	if (a2-a1<k || a4-a3<k) {puts("tokitsukaze");exit(0);}int s[]={a1,a2,a3,a4};sort(s,s+4);
	if (s[3]-s[1]>k || s[2]-s[0]>k) puts("once again");else puts("quailty");
}