#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 511, inf = 1000111222;

int n, k;
int QC = 0;
pair<int, int> query(vector<int> v) {
    ++QC;
    if (QC > n) {
        exit(228);
    }
    if (v.size() != k) {
        exit(228);
    }
    cout << "? ";
    for (int a : v) {
        cout << a + 1 << ' ';
    }
    cout << endl;
    cout.flush();
    int pos, val;
    cin >> pos >> val;
    --pos;
    return MP(pos, val);
}

void ans(int m) {
    cout << "! " << m << endl;
    cout.flush();
    exit(0);
}

int res[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    if (k == 1) {
        ans(1);
    }
    for (int i = 0; i < n; ++i) {
        res[i] = inf;
    }
    vector<int> v;
    for (int i = 0; i < k; ++i) {
        v.PB(i);
    }
    pair<int, int> qa = query(v);
    int pos1 = qa.F, val1 = qa.S;
    v.clear();
    for (int i = 0; i < k + 1; ++i) {
        if (i == pos1) {
            continue;
        }
        v.PB(i);
    }
    qa = query(v);
    int pos2 = qa.F, val2 = qa.S;
    int m = 0;
    for (int ind : v) {
        if (ind == pos2) {
            continue;
        }
        vector<int> vq = v;
        vq.erase(find(vq.begin(), vq.end(), ind));
        vq.push_back(pos1);
        qa = query(vq);
        if (val1 < val2) {
            if (qa.F == pos2) {
                ++m;
            }
        } else {
            if (qa.F != pos2) {
                ++m;
            }
        }
    }
    ans(m + 1);
    return 0;
}