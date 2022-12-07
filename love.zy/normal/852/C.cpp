#include<bits/stdc++.h>
using namespace std;

const int maxn=50005;
struct node
{
    int num,lb;
    bool operator < (const struct node &p)const
    {return num<p.num;}
}nu[maxn];
int n,a[maxn],ans[maxn];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    a[n]=a[0];
    for(int i=0;i<n;i++)
    {
        nu[i].lb=i;
        nu[i].num=n-a[i]-a[i+1];
    }
    sort(nu,nu+n);
    for(int i=n-1;i>=0;i--)
    {
        ans[nu[n-1-i].lb]=i;
    }
    for(int i=0;i<n;i++)
    {
        if(i>0)printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}