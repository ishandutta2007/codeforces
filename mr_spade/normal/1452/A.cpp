#include<cstdio>
#include<algorithm>
using std::swap;
inline void solve()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a>b)
        swap(a,b);
    printf("%d\n",a*2+((a==b)?0:(2*(b-a)-1)));
    return;
}
signed main()
{
    int T;scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}