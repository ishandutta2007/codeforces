#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 10;

typedef pair<int, int> pii;

vector<pii> x;
vector<int> where;

int getR(int p) {
    auto it = upper_bound(x.begin(), x.end(), pii(p, N));
    return it - x.begin() - 1;
}

int getL(int p) {
    auto it = lower_bound(x.begin(), x.end(), pii(p, 0));
    return it - x.begin();
}

int goRight(int, int);

int goLeft(int pos, int len) {
    //cerr << "l " << pos << " " << len << endl;
    int l = getL(x[pos].first - len);
    int dl = x[pos].first - x[l].first;
    return goRight(l, len - dl);    
}

int goRight(int pos, int len) {
    //cerr << "r " << pos << " " << len << endl;
    int r = getR(x[pos].first + len);
    long long dr = x[r].first - x[pos].first;
    if (dr != 0 && dr * 2 >= len)
        return goLeft(r, len - dr);
    len -= dr;
    int l = getL(x[r].first - len);
    if (l == pos && r == pos)
        return x[pos].second;
    int tot = x[r].first - x[l].first;
    int newLen = len % tot;
    if ((len / tot) % 2 == 1)
        return goLeft(l, newLen);
    return goRight(r, newLen);     
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int q;
    cin >> q;
    x.resize(n);
    where.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
    }  
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++)
        where[x[i].second] = i;
    for (int i = 0; i < q; i++) {
        int p, len;
        cin >> p >> len;
        p--;
        cout << goRight(where[p], len) + 1 << "\n";
    }   
    return 0;
}