#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
#define MP make_pair
#define F first
#define S second

const int N = 100 * 1000;
set<char> was[N];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int len;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        len = s.length();
        for (int j = 0; j < len; j++)
            if (s[j] != '?')
                was[j].insert(s[j]);
    }
    for (int i = 0; i < len; i++) {
        if (was[i].size() == 0)
            cout << 'a';
        else if (was[i].size() == 1)
            cout << *was[i].begin();
        else
            cout << "?";
    }

    return 0;
}