#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Inf = 1000000000;
const int Maxl = 26;

int n, k;
vector <int> let[Maxl];

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> k; cin.ignore();
    string s;
    getline(cin, s);
    for (int i = 0; i < k; i++)
        let[s[i] - 'a'].push_back(i);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        ll res = 0;
        for (int j = 0; j < s.length(); j++) {
            int best = Inf;
            int ind = upper_bound(let[s[j] - 'a'].begin(), let[s[j] - 'a'].end(), j) - 
                      let[s[j] - 'a'].begin();
            if (ind < let[s[j] - 'a'].size()) best = min(best, let[s[j] - 'a'][ind] - j);
            if (ind > 0) best = min(best, j - let[s[j] - 'a'][ind - 1]);
            if (best == Inf) best = s.length();
            res += best;
        }
        cout << res << endl;
    }
    return 0;
}