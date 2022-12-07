#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,a[MAXN],L,R,mid;
bool check()
{
    int p=n-mid;
    for(int i=1;i<=mid;i++)
        if(2*a[i]>a[p+i]) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    L=0,R=n/2;
    while(L<R)
    {
        mid=(L+R+1)>>1;
        if(check()) L=mid;
        else R=mid-1;
    }
    printf("%d\n",n-L);
    return 0;
}