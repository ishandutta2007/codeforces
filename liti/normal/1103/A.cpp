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

int main(){
    string s;
    cin >> s;

    int rcnt = 0, ccnt = 0;

    for(auto x: s) 
        if( x == '0' ) 
            cout << 1 << " " << (1 + (ccnt++ % 4)) <<'\n';
        else
            cout << 4 << " " << (1 + 2 * (rcnt++ % 2)) << '\n';

    return 0;
}