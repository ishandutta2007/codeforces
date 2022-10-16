#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()

using namespace std;

constexpr int N = 1e6 + 1;

string s, t;

int pfunc(string str) {
    vector<int> p(str.size(), 0);
    int st = 0;
    for (int i = 1; i < str.size(); ++i) {
        p[i] = max(min(min(p[st] - i + st, p[i - st]), int(str.size()) - i), 0);
        while (i + p[i] < str.size() && str[i + p[i]] == str[p[i]])
            ++p[i];
        if (i + p[i] > st + p[st])
            st = i;
        if (i + p[i] == str.size())
            return p[i];
    }
    return 0;
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> s >> t;
    int c = pfunc(t);
    int z = count(all(s), '0'), o = s.size() - z;
    int az = count(t.begin() + c, t.end(), '0'), ao = t.size() - c - az;
    int cz = count(all(t), '0') - az, co = c - cz;
    if (z < cz || o < co) {
        cout << s;
        return 0;
    }
    cout << t.substr(0, c);
    z -= cz, o -= co;
    string as = t.substr(c);
    while (z >= az && o >= ao)
        cout << as, z -= az, o -= ao;
    cout << string(z, '0') << string(o, '1') << '\n';
    return 0;
}