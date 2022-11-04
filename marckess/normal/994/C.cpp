#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

struct Punto {
    int x, y;

    Punto operator - (Punto ot) {
        return {x - ot.x, y - ot.y};
    }

    int operator ^ (Punto ot) {
        return x * ot.y - y * ot.x;
    }

    void leer () {
        cin >> x >> y;
    }
};

int md (Punto o, Punto p, Punto q) {
    int d = (o - p) ^ (o - q);
    if (d)
        return d / abs(d);
    return 0;
}

vector<Punto> a(4), b(4);
bool res = 0;

void intersecta () {
    for (int i = 0; i < 4; i++) {
        Punto p = a[i], q = a[(i+1)%4];
        for (int j = 0; j < 4; j++) {
            Punto p1 = b[j], q1 = b[(j+1)%4];
            res |= md(p, q, p1) != md(p, q, q1) && md(p1, q1, p) != md(p1, q1, q);
        }
    }
}

void dentro () {
    int _[2] = {0};
    for (int i = 0; i < 4; i++) {
        Punto p = a[i], q = a[(i+1)%4];
        for (int j = 0; j < 4; j++) {
            int d = md(p, q, b[j]);
            if (!d)
                return;
            if (d == 1)
                _[0]++;
            else
                _[1]++;
        }
    }

    res |= !_[0] || !_[1];
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    for (int i = 0; i < 4; i++)
        a[i].leer();

    for (int i = 0; i < 4; i++)
        b[i].leer();

    intersecta();
    dentro();
    swap(a, b);
    dentro();

    if (res)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}