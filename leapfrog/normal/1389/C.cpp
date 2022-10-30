#include<bits/stdc++.h>
using namespace std;
int t,n,mx=0;char c[2000005];
inline int ji(int x) {int r=0;for(int i=1;i<=n;i++) if(x==c[i]-'0') r++;return r;}
inline int ou(int x,int y) {int r=0,t=x;for(int i=1;i<=n;i++) if(t==c[i]-'0') r++,t=x+y-t;return (r&1)?r-1:r;}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",c+1),n=strlen(c+1),mx=0;
		for(int i=1;i<=n;i++) c[i+n]=c[i];
		for(int i=0;i<10;i++) mx=max(mx,ji(i));//printf("%d : %d\n",i,ji(i));
		for(int i=0;i<10;i++) for(int j=0;j<10;j++) if(i!=j) mx=max(mx,ou(i,j));//printf("%d , %d : %d\n",i,j,ou(i,j));
		printf("%d\n",n-mx);
	}
	return 0;
}