#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, c, d;
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        vector<int>v2, v;
        for(i=0;i++<n;)
        {
            scanf("%d", &a);
            if(a%2==0)v.push_back(a);
            else v2.push_back(a);
        }
        for(i=0;i<v2.size();i++)v.push_back(v2[i]);int ans=0;
        for(i=0;i<v.size();i++)
        {
            for(j=i+1;j<v.size();j++)
            {
                if(__gcd(v[i], 2*v[j])>1)ans++;
            }
        }
        printf("%d\n", ans);
    }
}