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

const int N = 2 * 1000 * 100 + 100;
int a[N]; 

int main(){
    ios::sync_with_stdio(false); cin.tie(0); 
    int n;
    cin >> n;
    for(int i =0; i < n; i++) 
        cin >> a[i]; 

    ll ans = a[n-1]; 
    int last = a[n-1]; 

    for(int i = n-2; i >= 0; i--) { 
        int v = min(a[i], last - 1); 
        v = max(0, v); 
        last = v; 
        ans += v; 
    }

    cout << ans << endl;
    return 0;
}