#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,a[maxn]; // a[i]>a[j], i>j X
int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<n;i++)
            if(a[i-1]>a[i])
                break;
        if(i<n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}