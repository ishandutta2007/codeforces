#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
const int maxc=100005;
int n,m,c[maxn];
ll s[1][maxc],cnt[1][maxc],ans;
inline int getid(int x,int y) { return x*m+y; }
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n*m;i++) scanf("%d",&c[i]);
    ans=0;

    for(i=0;i<maxc;i++) s[0][i]=cnt[0][i]=0; // s[1][i]=cnt[1][i]=0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            s[0][c[getid(i,j)]]+=i,cnt[0][c[getid(i,j)]]++;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            ans+=s[0][c[getid(i,j)]]-cnt[0][c[getid(i,j)]]*i;
                // -s[1][c[getid(i,j)]]+cnt[1][c[getid(i,j)]]*i;
        for(j=0;j<m;j++)
            s[0][c[getid(i,j)]]-=i,cnt[0][c[getid(i,j)]]--;
            // s[1][c[getid(i,j)]]+=i,cnt[1][c[getid(i,j)]]++;
    }
    // printf("%lld\n",ans);

    for(i=0;i<maxc;i++) s[0][i]=cnt[0][i]=0; // s[1][i]=cnt[1][i]=0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            s[0][c[getid(i,j)]]+=j,cnt[0][c[getid(i,j)]]++;
    for(j=0;j<m;j++)
    {
        for(i=0;i<n;i++)
            ans+=s[0][c[getid(i,j)]]-cnt[0][c[getid(i,j)]]*j;
                // -s[1][c[getid(i,j)]]+cnt[1][c[getid(i,j)]]*j;
        for(i=0;i<n;i++)
            s[0][c[getid(i,j)]]-=j,cnt[0][c[getid(i,j)]]--;
            // s[1][c[getid(i,j)]]+=j,cnt[1][c[getid(i,j)]]++;
    }
    printf("%lld\n",ans);
    return 0;
}