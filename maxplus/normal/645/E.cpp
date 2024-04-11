#include <iostream>
#include <cstring>

using namespace std;

const int mod = 1000000007;
int n, k;
string s;
int last[256], pos[256];
char ll = 'z';

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k, cin.get(), getline(cin, s);
    ll = 'a' + k - 1;
    memset(pos, 255, sizeof(pos));
    for (int i = 0; i < s.size(); ++i)
    {
        ++last[s[i]];
        for (int l = 'a'; l <= ll; ++l) if (l != s[i])
        {
            last[s[i]] += last[l];
            if (last[s[i]] >= mod)
                last[s[i]] -= mod;
        }
        pos[s[i]] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        int bl = ll;
        for (int l = 'a'; l < ll; ++l)
            if (pos[l] < pos[bl])
                bl = l;
        pos[bl] = s.size() + i;
        ++last[bl];
        for (int l = 'a'; l <= ll; ++l) if (l != bl)
        {
            last[bl] += last[l];
            if (last[bl] >= mod)
                last[bl] -= mod;
        }
    }
    int ans(1);
    for (int l = 'a'; l <= ll; ++l)
    {
        ans += last[l];
        if (ans >= mod)
            ans -= mod;
    }
    cout << ans;
    return 0;
}