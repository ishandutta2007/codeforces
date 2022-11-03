#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
int n,L,a; 
int t[100005],l[100005];
int main()
{
    scanf("%d%d%d",&n,&L,&a);
    int ans=0,t0=0;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d%d",&t[i],&l[i]);
    	ans+=(t[i]-t0)/a;t0=t[i]+l[i];
	}
	ans+=(L-t0)/a;
	printf("%d",ans);
    return 0;
}