/*
Codeforces 1495A. Diamond Miner
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline ll rd()
{
	char c=getchar();ll x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
const int N=100005;
ll n,a[N],b[N];
int main()
{
    int T=rd();
    while(T--)
    {
        n=rd();db ans=0;
        int n1=0,n2=0;
        rep(i,1,n*2)
        {
            int x=abs(rd()),y=abs(rd());
            if(!x)b[++n2]=y;else a[++n1]=x;
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        rep(i,1,n)ans+=sqrt((db)(a[i]*a[i]+b[i]*b[i]));
        printf("%.10lf\n",(double)ans);
    }
    return 0;
}