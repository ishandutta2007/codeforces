#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct info {
    vec< int > x, a;
    vec< int > p;
    void print() {
        cout << "p : ";
        for(int t : p) {
            cout << t << " ";
        }
        cout << "\n";
        cout << "x : ";
        for(int t : x) {
            cout << t << " ";
        }
        cout << "\n";
        cout << "a : ";
        for(int t : a) {
            cout << t << " ";
        }
        cout << "\n";
    }
};

info get(string s) {
    info res;
    res.x.resize(s.size());
    res.a.resize(s.size());
    for(int i = 0;i < (int)s.size();i++) {
        if(s[i] != 'A') {
            res.p.push_back(i);
        }
        if(i > 0) {
            res.x[i] = res.x[i - 1];
            res.a[i] = res.a[i - 1];
        }else {
            res.x[i] = res.a[i] = 0;
        }
        if(s[i] == 'A') {
            res.a[i]++;
        }else {
            res.x[i]++;
        }
    }
    return res;
}

pii get(const info& t, int l, int r) {
    int x = t.x[r] - (l > 0 ? t.x[l - 1] : 0);
    if(x == 0) {
        return make_pair(0, r - l + 1);
    }
    int j = upper_bound(ALL(t.p), r) - t.p.begin() - 1;
    j = t.p[j];
    int a = t.a[r] - t.a[j];
    return make_pair(x, a);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t;

    cin >> s >> t;

    info is = get(s);
    info it = get(t);

//    is.print();
//    it.print();

    int q;

    cin >> q;

    for(int i = 0;i < q;i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--;
        r1--;
        l2--;
        r2--;
        pii p1 = get(is, l1, r1);
        pii p2 = get(it, l2, r2);
//        cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << "\n";
//        continue;
        if(p1.first > p2.first || (p1.first - p2.first) % 2 || p1.second < p2.second) {
            cout << "0";
        }else {
            int nx = p2.first - p1.first;
            int na = p1.second - p2.second;
            if(nx == 0) {
                if(na == 0) {
                    cout << "1";
                }else {
                    if(na % 3) {
                        cout << "0";
                    }else {
                        cout << "1";
                    }
                }
            }else {
                if(na == 0) {
                    if(p1.first == 0) {
                        cout << "0";
                    }else {
                        cout << "1";
                    }
                }else {
                    cout << "1";
                }
            }
        }
    }

    cout << "\n";

    return 0;
}