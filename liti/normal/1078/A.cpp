//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii; 
typedef long double ld;

ld gg(ld x1, ld y1, ld x2, ld y2) { 
    ld x = (x1 - x2);
    ld y = (y1 - y2); 
    return sqrt(x*x+y*y); 
}

int main() {
    int aa, bb, cc;
    cin >> aa >> bb >> cc;
    ld a, b, c;
    a = aa, b = bb, c = cc;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ld mn = (ll)abs(x1 - x2) + abs(y1-y2);

    if( aa ) { 
        ld x1p = ( -c - (y1 * b) ) / a;
        ld x2p = ( -c - (y2 * b) ) / a; 
        mn = min( mn , abs(x1p - x1) + abs(x2p - x2) + gg(x1p,y1,x2p,y2) );
    }
    if( bb ) { 
        ld y1p = ( -c - (x1 * a) ) / b;
        ld y2p = ( -c - (x2 * a) ) / b; 
        mn = min( mn , abs(y1p - y1) + abs(y2p - y2) + gg(x1,y1p,x2,y2p) );
    }

    if( aa && bb ) { 
        ld x1p = ( -c - (y1 * b) ) / a;
        ld x2p = ( -c - (y2 * b) ) / a; 
        ld y1p = ( -c - (x1 * a) ) / b;
        ld y2p = ( -c - (x2 * a) ) / b; 
        mn = min( mn , abs(y1p - y1) + abs(x2p - x2) + gg(x1,y1p,x2p,y2) );
        mn = min( mn , abs(x1p - x1) + abs(y2p - y2) + gg(x1p,y1,x2,y2p) );
    }


    cout << fixed << setprecision(30); 
    cout << mn << endl;

    return 0;
}