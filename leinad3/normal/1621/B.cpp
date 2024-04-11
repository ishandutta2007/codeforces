#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, A[100010];
map<pair<int, int>, int>mp;
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        int mx=0, mn=1e9+1;
        set<int>x, nn;
        mp.clear();
        for(i=0;i++<n;)
        {
            scanf("%d %d %d", &a, &b, &k);if(mp.find({a, b})==mp.end())mp[{a, b}]=1e9+1;if(mp[{a, b}]>k)mp[{a, b}]=k;
            A[i]=k;
            if(mx<b)
            {
                mx=b;
                x.clear();
                x.insert(k);
            }
            else if(mx==b)x.insert(k);
            if(mn>a)
            {
                mn=a;
                nn.clear();
                nn.insert(k);
            }
            else if(mn==a)nn.insert(k);
            int a=*(x.begin())+*(nn.begin());
            if(mp.find({mn, mx})!=mp.end())
            {
                printf("%d\n", min(mp[{mn, mx}], a));
            }
            else
            {
                printf("%d\n", a);
            }
        }
    }
}