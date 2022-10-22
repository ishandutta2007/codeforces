#include<bits/stdc++.h>
#define ll long long
#define N 300010
using namespace std;int d[N];
int main()
{
	int n,i,u,v;cin>>n;
	for (i=1;i<n;i++) cin>>u>>v,d[u]++,d[v]++;
	for (i=1;i<=n;i++) if (d[i]==2){puts("NO");exit(0);} puts("YES");
}