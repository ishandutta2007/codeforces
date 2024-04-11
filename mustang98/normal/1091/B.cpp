#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011, inf = 1000111222;

vector<pair<int, int> > kl, pod;
set<pair<int, int>> s;
int n;

bool check(pair<int, int> t, int used) {
    for (int i = 0; i < n; ++i) {
        if (i == used) {
            continue;
        }
        s.insert(pod[i]);
    }
    for (int i = 1; i < n; ++i) {
        pair<int, int> np = make_pair(t.F - kl[i].F, t.S - kl[i].S);
        if (s.count(np) == 0) {
            return false;
        }
        s.erase(s.find(np));
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    kl.resize(n);
    pod.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &kl[i].F, &kl[i].S);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &pod[i].F, &pod[i].S);
    }
    for (int i = 0; i < n; ++i) {
        if (check(MP(kl[0].F + pod[i].F, kl[0].S + pod[i].S), i)) {
            cout << kl[0].F + pod[i].F << ' ' << kl[0].S + pod[i].S << endl;
            return 0;
        }
    }

    return 0;
}