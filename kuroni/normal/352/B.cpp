#include <bits/stdc++.h>

using namespace std;

main()
{
    int n, i, a[100001],p[100001],tmp,cnt=0;
    bool check[100001];
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    fill(begin(check),end(check),true);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>tmp;
        if (check[tmp])
        {
            if ((p[tmp] == 0) || (p[tmp] == i - a[tmp]))
            {
                if (a[tmp] != 0) p[tmp] = i - a[tmp];
                a[tmp] = i;
            }
            else check[tmp] = false;
        }
    }
    for (i = 1; i <= 100000; i++) if ((check[i]) && (a[i] != 0)) cnt++;
    cout<<cnt<<endl;
    for (i = 1; i <= 100000; i++) if ((check[i]) && (a[i] != 0)) cout<<i<<" "<<p[i]<<endl;
}