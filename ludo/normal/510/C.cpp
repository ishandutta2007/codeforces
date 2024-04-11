#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

int n, lens[MAX];
string strs[MAX];

bool vis[26] = {};
set<int> high[26], low[26];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
        lens[i] = strs[i].size();
    }

    for (int i = 1; i < n; i++) {
        int k = 0;
        while (k < lens[i] && k < lens[i - 1] && strs[i - 1][k] == strs[i][k]) {
            k++;
        }
        if (k == lens[i] || k == lens[i - 1]) {
            if (lens[i - 1] > lens[i]) {
                cout << "Impossible" << endl;
                return 0;
            }
        } else {
            // strs[i - 1][k] has to go before strs[i][k]
            int left = strs[i - 1][k] - 'a';
            int right = strs[i][k] - 'a';

            high[left].insert(right);
            low[right].insert(left);
        }
    }

    char str[26];
    int nstr = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < 26; i++) {
            if (!vis[i] && low[i].size() == 0) {
                flag = true;
                str[nstr++] = 'a' + i;
                vis[i] = true;

                for (set<int>::iterator it = high[i].begin(); it != high[i].end(); ++it) {
                    low[*it].erase(i);
                }
            }
        }
    }
    if (nstr == 26) {
        for (int i = 0; i < 26; i++) {
            cout << str[i];
        }
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}