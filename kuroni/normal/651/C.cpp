#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> row;
map<ll,ll> col;
map<string,ll> app;
main()
{
    char str[50], tmp[20];
    ll n, i, x, y, ans=0;
    for (cin>>n,i=0;i<n;i++)
    {
        scanf("%I64d %I64d",&x,&y);
        sprintf(str,"%I64d",x);
        strcat(str," ");
        sprintf(tmp,"%I64d",y);
        strcat(str,tmp);
        ans += row[x] + col[y] - app[str];
        row[x]++;
        col[y]++;
        app[str]++;
    }
    printf("%I64d",ans);
}