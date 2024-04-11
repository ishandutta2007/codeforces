#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1111, inf = 1000111222;

string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> s;
    vector<int> ans;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '(') {
            continue;
        }
        int lst = -1;
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[j] == ')') {
                lst = max(lst, j);
            }
        }
        if (lst == -1) {
            break;
        }
        s[lst] = '.';
        ans.PB(i);
        ans.PB(lst);
    }
    if (ans.empty()) {
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << endl;
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int a : ans) {
        cout << a + 1 << ' ' ;
    }
    cout << endl;

    return 0;
}