#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int L = 30; 
const int N = L * 100 * 1000 + 10;

int go[N][2];
int sz[N];
int last = 1;

vector<int> to_vec(int x) {
    vector<int> res;
    for (int i = 0; i < L; i++, x /= 2)
        res.push_back(x % 2);
    reverse(res.begin(), res.end());
    return res;
}

void add(const vector<int>& s, int d) {
    int v = 0;
    for (int i = 0; i < L; i++) {
        sz[v] += d;
        if (!go[v][s[i]])
            go[v][s[i]] = last++;
        v = go[v][s[i]];
    }
    sz[v] += d;
}

int calc(const vector<int>& p, const vector<int>& l) {
    int res = 0;
    int v = 0;
    for (int i = 0; i < L; i++) {
        int move = -1;
        for (int c = 0; c < 2; c++) {
            int t = c ^ p[i];
            if (t == l[i] && go[v][c])
                move = go[v][c];
            if (t < l[i] && go[v][c])
                res += sz[go[v][c]];
        }
        if (move == -1)
            break;
        v = move;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t, p;
        cin >> t >> p;
        if (t == 1 || t == 2)
            add(to_vec(p), t == 1 ? 1 : -1);
        else {
            int l;
            cin >> l;
            cout << calc(to_vec(p), to_vec(l)) << "\n";
        }
    }
}