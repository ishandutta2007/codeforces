#include <bits/stdc++.h>
using namespace std;
const int N=1e5+4;
typedef long long ll;
const double PI=acos(-1.0);
struct node
{
    int pos,a;
};
node l[N],r[N];
int cmp1(node x,node y)
{
    return x.pos>y.pos;
}
int cmp2(node x,node y)
{
    return x.pos<y.pos;
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    int cnt=0,num=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        if(x<0)
        {
            l[cnt].pos=x;
            l[cnt++].a=y;
        }
        else
        {
            r[num].pos=x;
            r[num++].a=y;
        }
    }
    sort(l,l+cnt,cmp1);
    sort(r,r+num,cmp2);
    int ans=0;
    for(int i=0;i<num&&i<cnt;i++)
    {
        ans+=l[i].a;
        ans+=r[i].a;
    }
    if(num>cnt)
    {
        ans+=r[cnt].a;
    }
    else if(num<cnt)
    {
        ans+=l[num].a;
    }
    cout<<ans<<endl;


    return 0;
}