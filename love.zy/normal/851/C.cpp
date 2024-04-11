#include<bits/stdc++.h>
using namespace std;

struct node
{
    int a[6];
    void read()
    {
        for(int i=1;i<=5;i++)scanf("%d",&a[i]);
    }
    node operator - (const struct node &p)const
    {
        node ret;
        for(int i=1;i<=5;i++)ret.a[i]=a[i]-p.a[i];
        return ret;
    }
    int operator * (const struct node &p)const
    {
        int ret=0;
        for(int i=1;i<=5;i++)ret+=a[i]*p.a[i];
        return ret;
    }
}nd[1005];
int n;
vector<int> ans;

int main()
{
    scanf("%d",&n);
    if(n>243){printf("0\n");return 0;}
    for(int i=1;i<=n;i++)nd[i].read();
    for(int i=1;i<=n;i++)
    {
        bool f=true;
        for(int j=1;j<n;j++)
        {
            if(j==i)continue;
            for(int k=j+1;k<=n;k++)
            {
                if(k==i)continue;
                if((nd[k]-nd[i])*(nd[j]-nd[i])>0){f=false;break;}
            }
            if(!f)break;
        }
        if(f)ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for(int p : ans)printf("%d\n",p);
    return 0;
}