#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxl = 26;
const int Maxn = 200005;

string s, t;
vector <int> wh[Maxl];
int l[Maxn], r[Maxn];

bool Solve()
{
    int cur = 0;
    for (int i = 0; i < s.length(); i++) {
        int ind = upper_bound(wh[s[i] - 'a'].begin(), wh[s[i] - 'a'].end(), cur) - 1 - wh[s[i] - 'a'].begin();
        if (ind < 0) return false;
        l[i] = wh[s[i] - 'a'][ind];
        if (cur < t.length() && s[i] == t[cur]) cur++;
    }
    cur = t.length() - 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        int ind = lower_bound(wh[s[i] - 'a'].begin(), wh[s[i] - 'a'].end(), cur) - wh[s[i] - 'a'].begin();
        if (ind == wh[s[i] - 'a'].size()) return false;
        r[i] = wh[s[i] - 'a'][ind];
        if (l[i] < r[i]) return false;
        if (cur >= 0 && s[i] == t[cur]) cur--;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio();
    getline(cin, s); getline(cin, t);
    for (int i = 0; i < t.length(); i++) wh[t[i] - 'a'].push_back(i);
    if (Solve()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}