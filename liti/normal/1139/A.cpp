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
    int n; cin >> n;

    string s;
    cin >> s; 
    ll ans = 0; 
    for(int i = 0; i < sz(s); i++) { 
        int d = s[i] - '0';
        if( d % 2 == 0 ) 
            ans += 1+i; 
    }
    cout << ans << endl;

    return 0;
}