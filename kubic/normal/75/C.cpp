#include <bits/stdc++.h>
using namespace std;
#define N 10005
int a,b,x,T,d[N];
int gcd(int a,int b) {return b?gcd(b,a%b):a;}
int main()
{
    scanf("%d %d %d",&a,&b,&T);x=gcd(a,b);
    for(int i=1;i*i<=x;++i) if(!(x%i)) {d[++d[0]]=i;if(i*i!=x) d[++d[0]]=x/i;}
    sort(d+1,d+d[0]+1);
    for(int i=1,l,r,t1,t2;i<=T;++i)
    {
        scanf("%d %d",&l,&r);
        t1=lower_bound(d+1,d+d[0]+1,l)-d;t2=upper_bound(d+1,d+d[0]+1,r)-d;
        if(t1<t2) printf("%d\n",d[t2-1]);else puts("-1"); 
    }
}