#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005];
inline bool cmp(int x,int y) {return x>y;}
inline bool chk(int *x,int *y) {for(int i=1;i<=n;i++) if(x[i]!=y[i]) return 0;return 1;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i),b[i]=c[i]=a[i];
	sort(b+1,b+n+1),sort(c+1,c+n+1,cmp);
	if(chk(a,b)&&chk(a,c)) return puts("-1"),0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j]) continue;else swap(a[i],a[j]);
			if(!chk(a,b)&&!chk(a,c)) return printf("%d %d\n",i,j),0;else swap(a[i],a[j]);
		}
	return puts("-1"),0;
}