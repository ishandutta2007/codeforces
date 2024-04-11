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
const int N=10005;
int n,k,a[N];
inline int qand(int x,int y)
{
    printf("and %d %d\n",x,y);
    fflush(stdout);
    int t;scanf("%d",&t);return t;
}
inline int qor(int x,int y)
{
    printf("or %d %d\n",x,y);
    fflush(stdout);
    int t;scanf("%d",&t);return t;
}
inline ll sum(int x,int y)
{
    ll t1=qand(x,y);
    ll t2=qor(x,y);
    return t1+t2;
}
int main()
{
    scanf("%d%d",&n,&k);
    ll s1=sum(1,2);
    ll s2=sum(1,3);
    ll s3=sum(2,3);
    ll t=(s1+s2+s3)/2;
    a[1]=t-s3;
    a[2]=t-s2;
    a[3]=t-s1;
    rep(i,4,n)a[i]=sum(1,i)-a[1];
    sort(a+1,a+n+1);
    printf("finish %d\n",a[k]);
    fflush(stdout);
    return 0;
}