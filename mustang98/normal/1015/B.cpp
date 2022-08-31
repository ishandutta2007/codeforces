#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 55, inf = 1000111222;

string s, t;
string s1, t1;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cin >> s >> t;
    s1 = s;
    t1 = t;
    sort(s1.begin(), s1.end());
    sort(t1.begin(), t1.end());
    if (s1 != t1) {
        cout << -1;
        return 0;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int st = -1;
        for (int j = i; j < n; ++j) {
            if (s[j] == t[i]) {
                st = j;
                break;
            }
        }
        while (st > i) {
            ans.PB(st - 1);
            swap(s[st - 1], s[st]);
            --st;
        }
    }
    cout << ans.size() << endl;
    for (int a : ans) {
        cout << a + 1 << ' ';
    }

    return 0;
}