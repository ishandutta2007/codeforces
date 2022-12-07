#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1000010;
int n,prime[MAXN],tot;
bool p[MAXN];
void get_prime(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!p[i]) prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<=n;j++)
        {
            p[i*prime[j]]=true;
            if(i%prime[j]==0) break;
        }
    }
}
int main()
{
    scanf("%d",&n);
    get_prime(n);
    for(int i=2;i<n;i++)
        if(p[i]&&p[n-i]) {printf("%d %d\n",i,n-i);break;}
    return 0;
}