#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define pb push_back
int T,n,s;
void slv()
{
	scanf("%d",&n);s=0;
	for(int i=1,x;i<=n;++i) scanf("%d",&x),s+=x-1;
	puts(s&1?"errorgorn":"maomao90");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}