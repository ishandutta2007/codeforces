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
	char c=getchar();int x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=100005;
int n,m;char s[N],t[N];
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();m=rd();
		rep(i,1,m)t[i]=0;
		rep(i,1,n)
		{
			scanf("%s",s+1);
			rep(j,1,m)t[j]+=s[j];
		}
		rep(i,1,n-1)
		{
			scanf("%s",s+1);
			rep(j,1,m)t[j]-=s[j];
		}
		rep(i,1,m)printf("%c",t[i]);
		puts("");
	}
	return 0;
}