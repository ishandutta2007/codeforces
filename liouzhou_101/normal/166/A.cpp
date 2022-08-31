#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
    int a,b;
}p[100];

bool cmp(node x,node y)
{
    return x.a>y.a||(x.a==y.a&&x.b<y.b);
}

int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>p[i].a>>p[i].b;
    sort(p+1,p+n+1,cmp);
    int ans=1;
    int i=k;
    while (p[i-1].a==p[k].a&&p[i-1].b==p[k].b)
    {
        --i;
        ++ans;
    }
    i=k;
    while (p[i+1].a==p[k].a&&p[i+1].b==p[k].b)
    {
        ++i;
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}