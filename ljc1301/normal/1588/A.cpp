#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,a[maxn],b[maxn];
inline bool check()
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]>b[i] || a[i]+1<b[i])
            return false;
    return true;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n;i++) scanf("%d",&b[i]);
        sort(a,a+n),sort(b,b+n);
        printf("%s\n",check()?"YES":"NO");
    }
    return 0;
}