
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

const int MAX_N = 3e5 + 5;

int n, m;
int a[MAX_N], b[MAX_N];

bool checkXY(int x, int y) {
    FOR(i, m) {
        if(a[i] != x && a[i] != y && b[i] != x && b[i] != y) {
            return false;
        }
    }
    return true;
}

bool checkX(int x) {
    FOR(i, m) {
        if(a[i] != x && b[i] != x) {
            return checkXY(x, a[i]) || checkXY(x, b[i]);
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m;
    FOR(i, m) {
        cin >> a[i] >> b[i];
    }
    if(checkX(a[0]) || checkX(b[0])) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
}