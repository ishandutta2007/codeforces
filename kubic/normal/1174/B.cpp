#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,a[N];bool vs[5];
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]),vs[a[i]&1]=1;
	if(vs[0] && vs[1]) sort(a+1,a+n+1);for(int i=1;i<=n;++i) printf("%d ",a[i]);
}