#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
typedef pair<int,int> pii;
#define x first
#define y second
pii a[maxn];
set<pii> s;
int n;
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    a[n]=a[0];
    for(i=0;i<n;i++)
        a[i]=pii(a[i].x-a[i+1].x,a[i].y-a[i+1].y);
    s.clear();
    for(i=0;i<n;i++)
        s.insert(a[i]);
    for(i=0;i<n;i++)
        if(!s.count(pii(-a[i].x,-a[i].y)))
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}