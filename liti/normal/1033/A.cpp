//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii; 

int gg(int a) { 
    if( a < 0 ) return -1;
    else
        return 1;
}

pii get(int ax, int ay, int bx, int by) {
    return pii( gg(bx - ax) , gg(by - ay) );
}

int main() {
    int ax, ay;
    int bx, by;
    int cx, cy;
    int n; cin >> n;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    if( get(ax, ay, bx, by) == get(ax, ay, cx, cy) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}