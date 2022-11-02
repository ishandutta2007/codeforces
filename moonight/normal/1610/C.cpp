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
const int N=200005;
int n,a[N],b[N];
inline bool chk(int x)
{
    int s=0;
    per(i,n,1)
    {
        int l=x-b[i]-1,r=a[i];
        if(s>=l&&s<=r)s++;
    }
    return s>=x;
}
int main()
{
    int T=rd();
    while(T--)
    {
        n=rd();
        rep(i,1,n)a[i]=rd(),b[i]=rd();
        int l=1,r=n+1;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(chk(m))l=m;else r=m;
        }
        printf("%d\n",l);
    }
    return 0;
}