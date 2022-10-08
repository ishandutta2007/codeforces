
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define ll long long
#define VI vector<int>

using namespace std;

const int MAX_N = 2005;
int n;
int a[MAX_N];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> e, o;
    FOR(i, n) {
        cin >> a[i];
        (a[i] % 2 == 0 ? e : o).push_back(a[i]);
    }
    sort(all(e));
    sort(all(o));
    for(int i = 1; i < (int) e.size(); i++) {
        e[i] += e[i - 1];
    }
    for(int i = 1; i < (int) o.size(); i++) {
        o[i] += o[i - 1];
    }
    if(abs((int) e.size() - (int) o.size()) <= 1) {
        cout << 0 << endl;
    }else if(e.size() > o.size()) {
        cout << e[e.size() - o.size() - 2] << endl;
    }else {
        cout << o[o.size() - e.size() - 2] << endl;
    }
}