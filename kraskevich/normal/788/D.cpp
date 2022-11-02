#include <bits/stdc++.h>    
using namespace std;

const int INF = int(1e8);

set<int> inter;

int ask(int x, int y) {
    cout << 0 << " " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

void go(int l, int r) {
    if (l > r)
        return;
    int m = (l + r) / 2;
    int dist = ask(m, m);
    if (dist == 0) 
        inter.insert(m);
    go(l, m - max(dist, 1));
    go(m + max(dist, 1), r);
}

int main() {
    go(-INF, INF);
    int unused = -INF;
    while (inter.count(unused))
        unused++;
    vector<int> v;
    vector<int> h;
    copy_if(inter.begin(), inter.end(), back_inserter(v), [=](int x) { return ask(x, unused) == 0; });
    copy_if(inter.begin(), inter.end(), back_inserter(h), [=](int y) { return ask(unused, y) == 0; });
    cout << 1 << " " << v.size() << " " << h.size() << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(h.begin(), h.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}