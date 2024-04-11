#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> inds;
set<int> used;

int cntq = 0;
pair<int, int> query(int i) {
    cout << "? " << i + 1 << endl;
    cout.flush();
    pair<int, int> res;
    cin >> res.F >> res.S;
    res.S--;
    return res;
}

void print_ans(int i) {
    cout << "! " << i << endl;
    cout.flush();
    exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    srand(time(NULL));

    int n, start, x;
    cin >> n >> start >> x;
    --start;

    vector<int> p;

    for (int i = 0; i < n; ++i) {
        p.PB(i);
    }

    random_shuffle(p.begin(), p.end());

    for (int i = 0; i < min(n, 1000); ++i) {
        inds.PB(p[i]);
    }

    int max_less, nxt;
    pair<int, int> res = query(start);
    if (res.F >= x) {
        print_ans(res.F);
    }

    max_less = res.F;
    nxt = res.S;

    for (int i : inds) {
        pair<int, int> res = query(i);
        if (res.F < x && res.F > max_less) {
            max_less = res.F;
            nxt = res.S;
        }
    }

    while (true) {
        if (nxt == -2) {
            print_ans(-1);
        }

        pair<int, int> res = query(nxt);
        if (res.F >= x) {
            print_ans(res.F);
        }
        nxt = res.S;
    }

    return 0;
}