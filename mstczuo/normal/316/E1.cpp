# include <iostream>
# include <cstdio>
using namespace std;
const int Mod = 1000000000;
int f[1000],a[1000];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    f[0] = f[1] = 1;
    for(int i=2; i<=n; i++)
        f[i] = ((long long)f[i-1] + f[i-2])%Mod;
    
    for(int i=1; i<=n; i++)
        scanf("%d",a+i);

    int t;
    long long ans;
    while(m--)
    {
        scanf("%d",&t);
        if(t==1)
        {
            int x;
            scanf("%d",&x);
            scanf("%d",&a[x]);
        }
        if(t==2)
        {
            ans = 0; int l,r;
            scanf("%d%d",&l,&r);
            for(int i=l;i<=r;i++)
                ans = (ans + (long long)a[i] * (long long)f[i-l])%Mod;
            cout << ans << endl;
        }
    }
    return 0;
}