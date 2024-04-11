#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n,a[MAXN],ans,cur;
multiset<int> S;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    cur=1;
    for(int i=1;i<=n;i++)
    {
        S.insert(a[i]);
        while((*S.rbegin())-(*S.begin())>1) S.erase(S.find(a[cur])),cur++;
        ans=max(ans,(int)S.size());
    }
    printf("%d\n",ans);
    return 0;
}