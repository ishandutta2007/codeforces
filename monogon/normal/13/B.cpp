
#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define pt complex<ll>
#define x real()
#define y imag()
#define dot(u, v) (conj(u) * (v)).x
#define cross(u, v) (conj(u) * (v)).y

istream &operator>>(istream &is, pt &p) {
    ll X, Y;
    is >> X >> Y;
    p = {X, Y};
    return is;
}

int t;
struct line {
    pt a, b;
};

line l[3], l2[3];

bool online(pt a, pt b, pt c) {
    return cross(b - a, c - a) == 0 && norm(b - a) < norm(c - a) && norm(b - c) < norm(c - a);
}

bool check(line l1, line l2, line l3) {
    if(l1.a != l2.a) return false;
    if(!online(l1.a, l3.a, l1.b)) return false;
    if(!online(l2.a, l3.b, l2.b)) return false;
    if(dot(l1.b - l1.a, l2.b - l2.a) < 0) return false;
    if(cross(l1.b - l1.a, l2.b - l2.a) == 0) return false;
    ll len1sq = norm(l3.a - l1.a), len2sq = norm(l3.a - l1.b);
    if(len2sq > 16 * len1sq || len1sq > 16 * len2sq) return false;
    len1sq = norm(l3.b - l2.a), len2sq = norm(l3.b - l2.b);
    if(len2sq > 16 * len1sq || len1sq > 16 * len2sq) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        for(int i = 0; i < 3; i++) {
            cin >> l[i].a >> l[i].b;
        }
        vector<int> v = {0, 1, 2};
        do {
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 3; j++) {
                    l2[v[j]] = l[j];
                    if((i >> j) & 1) swap(l2[v[j]].a, l2[v[j]].b);
                }
                if(check(l2[0], l2[1], l2[2])) {
                    cout << "YES" << endl;
                    goto endloop;
                }
            }
        }while(next_permutation(v.begin(), v.end()));
        cout << "NO" << endl;
        endloop:;
    }
}