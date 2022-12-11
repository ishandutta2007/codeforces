#include <stdio.h>
#define M 2000000
long long int force[M];
int n;

int bisearch(long long int val, int s, int e)
{
    if(val>=force[n-1]) return -1;
    if(val<force[0]) return -1;
    if(s==e) return s;
    int mid=(s+e+1)>>1;
    if(force[mid]<=val) return bisearch(val,mid,e);
    else return bisearch(val,s,mid-1);
}

int main()
{
    int i,q;
    long long num,arrow=0ll;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&force[i]);
        if(i) force[i]+=force[i-1];
    }
    for(i=0;i<q;i++)
    {
        scanf("%lld",&num);
        arrow+=num;
        printf("%d\n",n-1-bisearch(arrow,0,n-1));
        if(arrow>=force[n-1]) arrow=0ll;
    }
}