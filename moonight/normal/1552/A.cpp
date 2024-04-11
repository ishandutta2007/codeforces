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
const int N=45;
int n,ans;char s[N],t[N];
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();ans=0;
		scanf("%s",s+1);
		rep(i,1,n)t[i]=s[i];
		sort(t+1,t+n+1);
		rep(i,1,n)if(s[i]!=t[i])ans++;
		printf("%d\n",ans);
	}
	return 0;
}