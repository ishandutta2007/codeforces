#include<bits/stdc++.h>
using namespace std;
const int maxn=200;
int T,n,k;
int a[maxn+5],v[maxn+5];
void mark(int x)
{
	if(x<1||x>n) return;
	v[x]=1;
	return;
}
int check()
{
	for(int i=1;i<=n;i++) if(!v[i]) return 0;
	return 1;
}
int main()
{
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++) scanf("%d",&a[i]);
		memset(v,0,(n+5)*sizeof(int));
		int tim;
		for(tim=1;tim<=n;tim++)
		{
			for(int i=1;i<=k;i++) mark(a[i]+(tim-1)),mark(a[i]-(tim-1));
			if(check()) break;  
		}
		printf("%d\n",tim);
	}
	return 0;
}