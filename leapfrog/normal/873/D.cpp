#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,k,a[N];
inline void dfs(int x,int y)
{
	if(x+1>=y||!k) return;
	swap(a[((x+y)>>1)-1],a[(x+y)>>1]),k-=2;
	dfs(x,(x+y)>>1),dfs((x+y)>>1,y);
}
int main()
{
	scanf("%d%d",&n,&k),k--;
	for(int i=0;i<n;i++) a[i]=i+1;
	if(k&1) return puts("-1"),0;
	dfs(0,n);
	if(k) return puts("-1"),0;
	for(int i=0;i<n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}