#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5005;
int n;
ll s[maxn],tag[maxn],ans,cur;
int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans=0,cur=0;
        for(i=0;i<n;i++) scanf("%lld",&s[i]),tag[i]=0;
        for(i=0;i<n;i++)
        {
            cur+=tag[i];
            if(s[i]>cur)
            {
                ans+=s[i]-cur-1;
                tag[i+2]++;
            }
            else
            {
                tag[i+1]+=cur-s[i]+1;
                tag[i+2]-=cur-s[i];
            }
            if(i+s[i]<n) tag[i+s[i]+1]--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}