#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define pb push_back
int T,n;char a[N];
void slv()
{
	scanf("%s",a+1);n=strlen(a+1);
	if(a[n]=='A') {puts("No");return;}
	for(int i=1,nw=0;i<=n;++i)
	{
		if(a[i]=='A') ++nw;
		if(a[i]=='B') --nw;
		if(nw<0) {puts("No");return;}
	}puts("Yes");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}