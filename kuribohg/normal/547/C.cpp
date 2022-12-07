#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
vector<int> d[500010];
int prime[500010],tot,mu[500010];
bool p[500010];
void get_prime(int n)
{
    mu[1]=1,p[1]=true;
    for(int i=1;i<=n;i++)
    {
        if(!p[i]) prime[++tot]=i,mu[i]=-1;
        for(int j=1;j<=tot&&i*prime[j]<=n;j++)
        {
            p[i*prime[j]]=true;
            if(i%prime[j]) mu[i*prime[j]]=-mu[i];
            else break;
        }
    }
}
int n,Q,a[500010];
LL c[500010],cnt,ans;
bool inS[500010];
int main()
{
    get_prime(500000);
    for(int i=2;i<=500000;i++)
        if(mu[i])
        {
            for(int j=i;j<=500000;j+=i)
                d[j].push_back(i);
        }
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    while(Q--)
    {
        int x,p;
        scanf("%d",&x);
        p=a[x];
        if(inS[x])
        {
            int len=d[p].size();
            for(int i=0;i<len;i++)
            {
                int o=d[p][i];
                ans-=mu[o]*c[o]*(c[o]-1)/2;
                c[o]--;
                ans+=mu[o]*c[o]*(c[o]-1)/2;
            }
            cnt--;
            inS[x]=false;
        }
        else
        {
            int len=d[p].size();
            for(int i=0;i<len;i++)
            {
                int o=d[p][i];
                ans-=mu[o]*c[o]*(c[o]-1)/2;
                c[o]++;
                ans+=mu[o]*c[o]*(c[o]-1)/2;
            }
            cnt++;
            inS[x]=true;
        }
        printf("%I64d\n",cnt*(cnt-1)/2+ans);
    }
    return 0;
}