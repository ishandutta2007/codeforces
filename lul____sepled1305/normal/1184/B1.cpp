#include <bits/stdc++.h>
using namespace std;
pair<int, int> v[222222];
long long ans;
long long z[111111];
main()
{
    int s, b, a, d, g;
    scanf("%d %d", &s, &b);
    for(int i = 0;i < s;i++)
    {
        scanf("%d", &a);
        v[i].first = a;
        v[i].second = 1111111111+i;
    }
    for(int i = 0;i < b;i++)
    {
        scanf("%d %d", &d, &g);
        v[s+i].first = d;
        v[s+i].second = g;
    }
    sort(v, v+s+b);
    for(int i = 0;i < s+b;i++)
    {
        if(v[i].second > 1111111110)
            z[v[i].second - 1111111111] = ans;
        else ans += v[i].second;
    }
    printf("%lld", z[0]);
    for(int i = 1;i < s;i++)
        printf(" %lld", z[i]);
}