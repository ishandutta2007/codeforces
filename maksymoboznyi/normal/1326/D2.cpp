#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 2e6 + 5;
const int M = 998244353;
const int M1 = 1e9 + 7;
const int P = 37;
const int P1 = 53;

string s;
int h[N], rh[N], p[N];
int h1[N], rh1[N], p1[N];

bool good(int l, int r) {
    int h11 = h[r], h2 = rh[l];
    if (l != 0)
        h11 -= h[l - 1];
    h2 -= rh[r + 1];
    h11 = (h11 + M) % M;
    h2 = (h2 + M) % M;
    h2 *= p[l];
    h11 *= p[s.size() - 1 - r];
    h11 %= M;
    h2 %= M;

    int h3 = h1[r], h4 = rh1[l];
    if (l != 0)
        h3 -= h1[l - 1];
    h4 -= rh1[r + 1];
    h3 = (h3 + M1) % M1;
    h4 = (h4 + M1) % M1;
    h4 *= p1[l];
    h3 *= p1[s.size() - 1 - r];
    h3 %= M1;
    h4 %= M1;
    return h11 == h2 && h3 == h4;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int cur = -1;
        while ((cur + 2) * 2 <= s.size() && s[cur + 1] == s1[cur + 1])
            cur++;
        h[0] = s[0];
        p[0] = 1;
        for (int i = 1; i < s.size(); i++)
            p[i] = p[i - 1] * P % M, h[i] = (h[i - 1] + p[i] * s[i] % M) % M;
        rh[s.size() - 1] = s[s.size() - 1] * p[0] % M;
        rh[s.size()] = 0;
        int sz = s.size();

        for (int i = sz - 2; i >= 0; i--)
            rh[i] = (rh[i + 1] + s[i] * p[s.size() - 1 - i] % M) % M;

        h1[0] = s[0];
        p1[0] = 1;
        for (int i = 1; i < s.size(); i++)
            p1[i] = p1[i - 1] * P1 % M1, h1[i] = (h1[i - 1] + p1[i] * s[i] % M1) % M1;
        rh1[s.size() - 1] = s[s.size() - 1] * p1[0] % M1;
        rh1[s.size()] = 0;

        for (int i = sz - 2; i >= 0; i--)
            rh1[i] = (rh1[i + 1] + s[i] * p1[s.size() - 1 - i] % M1) % M1;


        if ((cur + 1) * 2 == s.size()) {
            cout << s << "\n";
            continue;
        }
        //cout << (rh[3] - rh[8] + M) % M << ' ' << (h[7] - h[2] + M) % M << endl;
        //cout << cur << ' ' << good(4, 8) << endl;
        int x1 = cur + 1, x2 = cur + 1;
        for (int l = 1; (cur + 1) * 2 + l <= s.size(); l++)
            if (good(cur + 1, cur + l))
                x1 = cur + 1, x2 = cur + l;
            else
                if (good(s.size() - cur - 2 - l + 1, s.size() - cur - 2))
                    x1 = s.size() - cur - 2 - l + 1, x2 = s.size() - cur - 2;
        string t = "";
       // cout << cur << ' ' << x1 << ' ' << x2 << ' ' << good(4, 8) << endl;
        for (int i = 0; i <= cur; i++)
            t += s[i];
        for (int i = x1; i <= x2; i++)
            t += s[i];
        for (int i = cur; i >= 0; i--)
            t += s[i];
        cout << t << "\n";
    }
    return 0;
}