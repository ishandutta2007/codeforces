#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(register int i=0;i<a.size();++i)
inline ll rd()
{
	char c=getchar();ll x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=4000005;
int n,P,s[N],ps[N];
inline int pls(int a,int b){a+=b;return a>=P?a-P:a;}
int main()
{
    n=rd();P=rd();
    rep(i,2,n)ps[n/i]=i;
    s[n]=1;int t=1;
    per(i,n-1,1)
    {
        s[i]=i==1?s[i+1]:pls(s[i+1],s[i+1]);
        t=max(t,ps[i]);
        rep(j,2,t)
            s[i]=pls(s[i],pls(s[i*j],P-s[min(n+1,(i+1)*j)]));
    }
    printf("%d\n",s[1]);
    return 0;
}