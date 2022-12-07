#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n;
LL v[MAXN],d[MAXN],p[MAXN];
bool used[MAXN];
vector<int> ans;
void work(int x)
{
    for(int i=x+1;i<=n;i++)
        p[i]-=d[x];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d%I64d%I64d",&v[i],&d[i],&p[i]);
    for(int i=1;i<=n;i++)
        if(p[i]>=0)
        {
            LL x=v[i];
            for(int j=i+1;j<=n;j++)
            {
                if(p[j]<0) continue;
                if(!x) continue;
                p[j]-=x;
                x--;
            }
            for(int j=i+1;j<=n;j++)
                if(p[j]<0&&!used[j]) work(j),used[j]=true;
            ans.push_back(i);
        }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    return 0;
}