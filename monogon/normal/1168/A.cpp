
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

bool check(int k) {
    b[0] = a[0];
    if(a[0] + k >= m) b[0] = 0;
    FORK(i, 1, n) {
        if(a[i] >= b[i - 1]) {
            b[i] = a[i];
            if(a[i] + k >= m && (a[i] + k) % m >= b[i - 1]) {
                b[i] = b[i - 1];
            }
        }else if(a[i] + k >= b[i - 1]) {
            b[i] = b[i - 1];
        }else {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m;
    FOR(i, n) {
        cin >> a[i];
    }
    int x = -1;
    for(int b = m; b >= 1; b /= 2) {
        while(!check(x + b)) {
            x += b;
        }
    }
    cout << (x + 1) << endl;
}