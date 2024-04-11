//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = -1;
const ld pi = 3.141592653589793;

ld cotan(ld i) { return(1 / tan(i)); }

int main(){
    int n, r;
    cin >> n >> r; 

    cout << fixed << setprecision(20);

    ld z = sin( pi / n );

    cout << r * z / (1-z) << endl;

    return 0;
}