#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 3e7
const int MAX=2e5+5;
int n;
int flag;
struct Node
{
    int c,d;
}a[MAX];
int check(int x)
{
    int res=x;
    for(int i=n-1;i>=0;i--)
    {
        res-=a[i].c;
        if(a[i].d==1&&res<1900) return 0;
        if(a[i].d==2&&res>=1900) return -1;
    }
    return 1;
}
int solve(int l,int r)
{
    flag=0;
    int mid;
    while(r-l>1)
    {
        mid=(l+r)/2;
        if(check(mid)>=0)l=mid;
        else r=mid;
    }
    if(check(l+1)>=0)l++;
    if(check(l)==1) {flag=1;return l;}
    return -1;
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].c,&a[i].d);
        int t=solve(-INF,INF);
        if(flag==1)
        {
            if(t==INF)cout<<"Infinity"<<endl;
            else cout<<t<<endl;
        }
        else cout<<"Impossible"<<endl;
    }
    return 0;
}