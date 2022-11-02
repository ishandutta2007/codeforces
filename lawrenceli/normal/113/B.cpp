#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 2005;
const ll MULT = 1e9 + 7;

string t, s_st, s_nd;
ll pow[MAXN], pre[MAXN];
bool good_st[MAXN], good_nd[MAXN];
ll arr[MAXN * MAXN];
int sze;

void init() {
    pow[0] = 1;
    for (int i=1; i<MAXN; i++) pow[i] = pow[i-1] * MULT;
    for (int i=0; i<t.length(); i++)
        pre[i+1] = pre[i] + pow[i] * t[i];

    for (int i=0; i+s_st.length() <= t.length(); i++)
        good_st[i] = t.substr(i, s_st.length()) == s_st;

    for (int i=s_nd.length()-1; i < t.length(); i++)
        good_nd[i] = t.substr(i - s_nd.length() + 1, s_nd.length()) == s_nd;

}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> t >> s_st >> s_nd;

    init();

    int lmin = max(s_st.length(), s_nd.length());

    for (int i=0; i<t.length(); i++)
        for (int j=i+lmin-1; j<t.length(); j++)
            if (good_st[i] && good_nd[j])
                arr[sze++] = (pre[j+1] - pre[i]) * pow[t.length() - i];

    sort(arr, arr + sze);
    sze = unique(arr, arr + sze) - arr;

    cout << sze << endl;
    return 0;
}