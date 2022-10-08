
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
#define LL long long
#define VI vector<int>

using namespace std;

// a white vertex is never deleted
// a yellow vertex with a white child is never deleted
// a yellow vertex with only yellow children is always deleted

const int MAX_N = 1e5 + 5;

int n;
int p[MAX_N], c[MAX_N];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    VI children[n + 1];
    FORK(i, 1, n + 1) {
        cin >> p[i] >> c[i];
        if(p[i] != -1) {
            children[p[i]].push_back(i);
        }
    }
    bool del = false;
    FORK(i, 1, n + 1) {
        if(p[i] == -1 || c[i] == 0)
            goto outer;
        for(int child : children[i]) {
            if(c[child] == 0)
                goto outer;
        }
        del = true;
        cout << i << " ";
        outer:;
    }
    if(!del) {
        cout << -1 << endl;
    }
}