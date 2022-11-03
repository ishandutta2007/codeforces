#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
set<int> del;
int n,a[maxn],l[maxn],r[maxn];
int ans[maxn],tot;
int gcd(int a,int b) { return b?gcd(b,a%b):a; }
int main()
{
    int T,i;
    set<int>::iterator it;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]),l[i]=(i+n-1)%n,r[i]=(i+1)%n;
        del.clear();
        for(i=0;i<n;i++)
            if(gcd(a[l[i]],a[i])==1)
                del.insert(i);
        for(tot=0,i=0;!del.empty();)
        {
            it=del.upper_bound(i);
            if(it==del.end()) it=del.begin();
            i=ans[tot++]=*it,del.erase(it);
            if(l[i]==i) break;
            r[l[i]]=r[i],l[r[i]]=l[i],i=r[i];
            if(del.count(i)) del.erase(i);
            if(gcd(a[i],a[l[i]])==1) del.insert(i);
        }
        printf("%d",tot);
        for(i=0;i<tot;i++) printf(" %d",ans[i]+1);
        printf("\n");
    }
    return 0;
}