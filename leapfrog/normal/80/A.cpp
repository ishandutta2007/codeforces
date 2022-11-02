#include<bits/stdc++.h>
using namespace std;
int n,m;
inline int check(int a)
{
	if(a==1) return 0;else if(a==2) return 1;
	for(int i=2,e=sqrt(a);i<=e;i++) if(a%i==0) return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(!check(n)||!check(m)) return puts("NO"),0;
	for(int i=n+1;i<m;i++) if(check(i)) return puts("NO"),0;
	return puts("YES"),0;
}