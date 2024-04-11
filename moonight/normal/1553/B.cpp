#include<bits/stdc++.h>
using namespace std;
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
const int N=1005;
int n,m;
char s1[N],s2[N];
inline bool chk1(int t,int p)
{
	rep(i,1,t)if(s2[i]!=s1[p-t+i])return 0;
	return 1;
}
inline bool chk2(int t,int p)
{
	rep(i,t,m)if(s2[i]!=s1[p-(i-t)])return 0;
	return 1;
}
int main()
{
	int T=rd();
	while(T--)
	{
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		n=strlen(s1+1);
		m=strlen(s2+1);
		int ff=0;
		rep(i,1,n)
		{
			rep(j,1,m)
			{
				if(j>i||m-j+1>i)continue;
				if(chk1(j,i)&&chk2(j,i))
				{
					ff=1;break;
				}
			}
			if(ff)break;
		}
		puts(ff?"YES":"NO");
	}
    return 0;
}