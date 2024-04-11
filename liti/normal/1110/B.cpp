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

const int N = 1000*100 + 100;

vector<int> curr;

int main(){
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k; 

    int ans = n;

    int last = -1;
    for(int i = 0; i < n; i++) { 
        int x;
        cin >> x;
        if( i ) {
            curr.push_back( x - last - 1 ); 
        }
        last = x;
    }

    sort( curr.begin(), curr.end() ); 
    for(int i = 0; i < n-k; i++)
        ans += curr[i]; 
    
    cout << ans << endl;

    return 0;
}