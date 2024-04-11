#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int, int> mp;
int a[200010];
vector<int> v;
bool cmp(int x, int y)
{
    return x < y;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        mp.clear();
        int n;
        scanf("%d",&n);
        int i;
        ll sum = 0;
        for(i=1; i<=n; i++) 
        {
            scanf("%d",&a[i]);
            sum += (ll)a[i];
        }
        sum *= 2LL;
        if(sum % n)
        {
            printf("0\n");
            continue;
        }
        ll x = sum / (ll)n;
        for(i=1; i<=n; i++)
        {
            if(mp[a[i]] == 0)
            {
                mp[a[i]]++;
                v.push_back(a[i]);
            }
            else mp[a[i]]++;
        }
        sort(v.begin(), v.end(), cmp);
        ll ans = 0;
        for(i=0; i<(int)v.size(); i++)
        {
            int cc = mp[v[i]];
            if(v[i] > x / 2LL) break;
            if(x % 2LL == 0 && v[i] == x / 2LL) ans += (ll)cc * (cc-1LL) / 2LL;
            else ans += mp[x - v[i]] * (ll)cc;
        }
        printf("%lld\n", ans);
    }
    return 0;
}