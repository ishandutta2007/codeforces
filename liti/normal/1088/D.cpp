//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii; 

int main() {
    int c = 0, d = 0; 
    cout << "? " << c << ' ' << d << endl;
    fflush(stdout);
    int r;
    cin >> r; 

    int a = 0, b = 0;

    for(int i = 29; i >= 0;i --) { 
        int cc = c | (1<<i);
        int dd = d | (1<<i); 
        cout << "? " << cc << ' ' << dd << endl;
        fflush(stdout);
        int rr;
        cin >> rr;

        if( r == rr ) { 
            cout << "? " << (c | (1<<i)) << " " << d << endl;
            fflush(stdout);
            int ret;
            cin >> ret;
            if( ret == -1 ) {
                a |= (1<<i);
                b |= (1<<i);
            }
        } else { 
            if( rr < r ) {
                a |= (1<<i);
                d |= (1<<i);
            } else {
                b |= (1<<i);
                c |= (1<<i);
            }
            cout << "? " << c << " " << d << endl;
            fflush(stdout);
            cin >> r;
        }
    }

    cout << "! " << a << " " << b << endl;
    fflush(stdout);

    return 0;
}