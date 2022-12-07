#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int dx[]={-1,-2,-1,1,2,1};
const int dy[]={2,0,-2,-2,0,2};
LL n,L,R,x,y,c;
int main()
{
    scanf("%I64d",&n);
    if(n==0) {puts("0 0");return 0;}
    L=1,R=1000000000;
    while(L<R)
    {
        LL mid=(L+R)>>1;
        if(mid*(mid+1)*3LL<n) L=mid+1;
        else R=mid;
    }
    x=2*L;
    c=n-L*(L-1)*3LL;
    for(int i=0;i<6;i++)
    {
        if(c>L) c-=L,x+=dx[i]*L,y+=dy[i]*L;
        else x+=dx[i]*c,y+=dy[i]*c,c=0;
    }
    printf("%I64d %I64d\n",x,y);
    return 0;
}