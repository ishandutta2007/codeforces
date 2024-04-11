#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,a[N],cntN[N],nw[N];
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]),++cntN[a[i]];
	for(int i=2;i<=100000;++i) if(cntN[i]>cntN[i-1]) {puts("-1");return 0;}
	printf("%d\n",cntN[1]);for(int i=1;i<=n;++i) printf("%d ",++nw[a[i]]);
}