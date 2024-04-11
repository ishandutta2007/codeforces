//In the name God
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int maxN = 1000 * 100 + 10;

vector<int> a[maxN];
int ans[maxN];

int main() {
    int n;
    cin >> n; 
    for(int i = 0; i < n; i++) { 
        int x;
        cin >> x; 
        a[x].pb(i);
    }
    int cnt = 1;
    for(int i = 0; i < n; i++) { 
        int s = sz(a[i]); 
        if( s % (n-i) != 0 ) { 
            cout << "Impossible" << endl;
            return 0;
        }
        for(int j = 0; j < sz(a[i]); j += n - i, cnt++) 
            for(int k = j; k < j + n - i; k++)
                ans[a[i][k]] = cnt;
    }
    cout << "Possible" << endl;
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0; 
}