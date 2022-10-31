//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

typedef pair<int,int> pii;
#define X first
#define Y second

ll cross(pii a, pii b, pii c) {
    return 1ll * (b.X - a.X) * (c.Y - a.Y) 
        - 1ll * (b.Y - a.Y) * (c.X - a.X);
}

ll dd(pii a, pii b) { 
    int x = a.X - b.X;
    int y = a.Y - b.Y;
    return 1ll * x * x + 1ll * y * y; 
}


const int maxN = 1000 * 100 + 100; 
pii a[2][maxN];

vector<pii> convex(pii* a, int n) { 
    sort(a, a + n); 

    vector<pii> r;
    for(int i = 0; i < n; i++) {
        while( r.size() > 1 && cross( r[int(r.size()) - 2], r[int(r.size())-1] , a[i] ) >= 0 )
            r.pop_back();
        r.push_back( a[i] ); 
    }

    int sz = r.size();
    for(int i = n - 1 ; i >= 0 ; i-- ) { 
        while( r.size() > sz && cross( r[int(r.size()) - 2], r[int(r.size())-1] , a[i] ) >= 0 )
            r.pop_back();
        r.push_back( a[i] ); 
    }

    r.pop_back();

    return r;
}

ll tav[maxN]; 
const int base = 701;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) 
        cin >> a[0][i].X >> a[0][i].Y; 

    for(int i = 0; i < m; i++)
        cin >> a[1][i].X >> a[1][i].Y;

    vector<pii> x = convex(a[0], n);
    vector<pii> y = convex(a[1], m); 

    cerr << x.size() << " " << y.size() << endl;

    if( x.size() == y.size() ) { 
        tav[0] = 1; 
        for(int i = 1; i < maxN; i++)
            tav[i] = tav[i-1] * base;

        int k = x.size();
        x.push_back(x[0]);
        y.push_back(y[0]);

        ll hL = 0;
        ll hA = 0;

        ll sumL = 0; 
        ll sumA = 0;

        ll bL = 0;
        ll bA = 0;

        for(int i = 0; i < k; i++) { 
            hA = hA * base + dd(x[i], x[i+1]);
            sumA += dd(x[i], x[i+1]); 
            int j = i - 1; 
            if( j < 0 ) j = k - 1;
            hL = hL * base + cross(x[i], x[j], x[i+1]);
            sumL += cross(x[i], x[j], x[i+1]);

            

            bA = bA * base + dd(y[i], y[i+1]);
            bL = bL * base + cross(y[i], y[j], y[i+1]);

            sumA -= dd(y[i], y[i+1]); 
            sumL -= cross(y[i], y[j], y[i+1]);
        }

        if( sumA == 0 && sumL == 0 ) { 
            for(int i = 0; i < k; i++) { 
                if( hA == bA && hL == bL ) { 
                    cout << "YES" << endl;
                    return 0;
                }

                bA -= tav[k-1] * dd(y[i], y[i+1]);
                bA = bA * base + dd(y[i], y[i+1]);

                int j = i - 1; 
                if( j < 0 ) j = k - 1;
                bL -= tav[k-1] * cross(y[i], y[j], y[i+1]);
                bL = bL * base + cross(y[i], y[j], y[i+1]);
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}