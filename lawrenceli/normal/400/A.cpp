#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int t; cin >> t;
    for (int i=0; i<t; i++) {
        string s; cin >> s;
        vector<pii> v;
        for (int j=1; j<=12; j++) {
            if (12 % j == 0) {
                int k = 12 / j;
                for (int l=0; l<k; l++) {
                    bool b = 1;
                    for (int m=0; m<j; m++)
                        if (s[m*k+l] == 'O') b = 0;
                    if (b) { v.push_back(pii(j, k)); break; }
                }
            }
        }
        cout << v.size() << ' ';
        for (int j=0; j<v.size(); j++)
            cout << v[j].first << 'x' << v[j].second << ' ';
        cout << '\n';
    }

    return 0;
}