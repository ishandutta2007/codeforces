#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
map <ll,ll> query;
ll tmp, t, i;
char ch;
ll conv(ll i)
{
    ll ans = 0, t = 0;
    while (i != 0)
    {
        ans += (ll)pow(10,t)*(i%2);
        t++;
        i /= 10;
    }
    return ans;
}
main()
{
    for (scanf("%d\n",&t), i = 0; i < t; i++)
    {
        scanf("%c %I64d\n", &ch ,&tmp);
        if (ch == '+') query[conv(tmp)]++;
        if (ch == '-') query[conv(tmp)]--;
        if (ch == '?') printf("%I64d\n", query[tmp]);
    }
}