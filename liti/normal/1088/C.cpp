//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii; 

const int maxN = 1000 * 100 + 10; 
int a[maxN];

int main() {
    int n;
    cin >> n;

    for(int i =0; i < n; i++) { 
        cin >> a[i]; 
    }
    int mod = n; 

    int sum = 0; 
    vector<pii> ans;
    for(int i = n - 1; i >= 0 ; i-- ) { 
        int v = (a[i] + sum) % mod; 
        int ta = ( i - v + mod ) % mod; 
        if( ta != 0 ) 
            ans.push_back( {i+1, ta} );
        sum = (sum + ta) % mod;
    }
    cout << ans.size() + 1 << '\n';
    for(auto x : ans) 
        cout << 1 << ' ' << x.first << ' ' << x.second << '\n';
    cout << 2 << ' ' << n << ' ' << n << endl;

    return 0;
}