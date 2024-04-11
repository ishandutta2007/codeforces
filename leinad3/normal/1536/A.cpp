#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, c;
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);vector<int>v;
        a=0;bool flag=false;
        for(i=0;i++<n;)
        {
            scanf("%d", &b);
            if(b<0&&!flag)
            {
                puts("NO");flag=true;
            }
            a=__gcd(a, b);
        }if(flag)continue;
        for(i=0;i<=200;i+=a)v.push_back(i);
        puts("YES");printf("%d\n", v.size());
        for(i=0;i<v.size();i++)printf("%d ", v[i]);puts("");
        //w:;
    }
}