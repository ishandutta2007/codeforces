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
int n,m;char s1[100005],s2[100005];
int main()
{
	int T=rd();
	while(T--)
	{
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		n=strlen(s1+1);
		m=strlen(s2+1);
		reverse(s1+1,s1+n+1);
		reverse(s2+1,s2+m+1);
		int p=0;
		rep(i,1,m)
		{
			p++;
			while(p<=n&&s2[i]!=s1[p])p+=2;
			if(p>n)break;
		}
		if(p>n)puts("NO");
		else puts("YES");
	}
    return 0;
}