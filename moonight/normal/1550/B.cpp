#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=105,inf=1e9;
int n,a,b,m;char s[N];
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();a=rd();b=rd();m=1;
		scanf("%s",s+1);
		if(b>=0)
		{
			printf("%d\n",n*(a+b));
			continue;
		} 
		rep0(i,1,n)if(s[i]!=s[i+1])m++;
		m=m/2+1;
		printf("%d\n",n*a+m*b);
	}
	return 0;
}