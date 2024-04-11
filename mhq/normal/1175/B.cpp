#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const ll LIM = (1LL << 32);
int l;
const int maxN = (int)1e5 + 100;
int par[maxN];
int tp[maxN];
const int ADD = 1;
const int FOR = 2;
int val[maxN];
const int EN = 3;
ll solve(int i, int j) {
    if (i > j) return 0;
    if (tp[i] == ADD) {
        return min(LIM, solve(i + 1, j) + 1);
    }
    int to = par[i];
    ll s1 = solve(i + 1, to - 1);
    if (s1 >= LIM / val[i]) s1 = LIM;
    else s1 *= val[i];
    return min(LIM, s1 + solve(to + 1, j));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> l;
    vector < int > nums;
    for (int i = 1; i <= l; i++) {
        string s;
        cin >> s;
        if (s == "for") {
            cin >> val[i];
            tp[i] = FOR;
            nums.push_back(i);
        }
        else if (s == "add") {
            tp[i] = ADD;
        }
        else if (s == "end") {
            par[nums.back()] = i;
            nums.pop_back();
        }
    }
    /*for (int i = 1; i <= l; i++) {
        if (tp[i] == FOR) {
            cout << val[i] << " " << par[i] << " " << i << endl;
        }
    }*/
    auto it = solve(1, l);
    if (it >= LIM) cout << "OVERFLOW!!!";
    else cout << it;
    return 0;
}