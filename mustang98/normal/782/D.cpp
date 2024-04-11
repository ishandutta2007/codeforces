#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011;
string team[max_n];
string city[max_n];
int ans[max_n] = {0};

set<string> sett;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string a, b;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        team[i] = a.substr(0, 3);
        city[i] = a.substr(0, 2) + b[0];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (team[i] == team[j]) {
                ans[i] = 2;
                ans[j] = 2;
            }
        }
        if (ans[i] == 2) {
            sett.insert(city[i]);
        }
    }

    while (true)
    {
        bool is_changed = false;
        for (int i = 0; i < n; ++i) {
            if (ans[i] != 0) continue;
            if (sett.count(team[i])) {
                ans[i] = 2;
                is_changed = true;
                sett.insert(city[i]);
            } else if (sett.count(city[i])) {
                ans[i] = 1;
                is_changed = true;
                sett.insert(team[i]);
            }
        }
        if (!is_changed) break;
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 0) ans[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        string a = (ans[i] == 1 ? team[i] : city[i]);
        for (int j = i + 1; j < n; ++j) {
            string b = (ans[j] == 1 ? team[j] : city[j]);
            if (a == b) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << (ans[i] == 1 ? team[i] : city[i]) << "\n";
    }
    return 0;
}