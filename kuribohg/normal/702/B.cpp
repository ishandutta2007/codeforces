#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
typedef long long LL;
const int MAXN=100010;
map<int,int> M;
int n,a[MAXN];
LL ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) M[a[i]]++;
    for(int i=1;i<=n;i++)
    {
        for(int k=0;k<31;k++)
        {
            ans+=M[(1<<k)-a[i]];
            if(k>0&&a[i]==(1<<(k-1))) ans--;
        }
    }
    printf("%I64d\n",ans>>1);
    return 0;
}