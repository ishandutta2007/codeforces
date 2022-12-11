#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
const int INF = 2e9;
const int mx = 1e5;

struct C{
    int a,b;
    C(){};
    C(int a,int b):a(a),b(b){};
    bool operator < (const C &X) const{
        return a<X.a;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    int x;
    cin >> x;
    if(x==1) cout << -1;
    else cout << x << ' ' << x;
}