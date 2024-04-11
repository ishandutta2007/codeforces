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

const int inf = 1e9;
const int maxN = 1000 * 100 + 100; 
const int maxK = 2000 * 100 + 100; 

vector<int> taj[maxK];

ll x[maxN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    for(int i = 1; i < maxK; i++) 
        for(int j = min((ll)maxK,1ll*i*i) ; j < maxK; j += i) 
            if( (i + j/i) % 2 == 0 )
                taj[j].push_back( i );

    int n;
    cin >> n;
    for(int i = 1; i < n; i+=2 )
        cin >> x[i];

    int v = 0; 
    for(int i = 0; i < n; i+=2) { 
        int nv = inf;
        int f = -1;
        for(auto d: taj[x[i+1]]) { 
            int x = d;
            int y = ::x[i+1]/x;
            int a = (y-x)/2;
            int b = (x+y)/2;
            if( a > v && b < nv ) { 
                nv = b;
                f = a;
            }
        }
        if( nv == inf ) { 
            cout << "No" << endl;
            return 0;
        }
        x[i] = 1ll*f*f - 1ll*v*v;
        v = nv;
    }

    cout << "Yes" << endl;
    for(int i = 0; i < n; i++)
        cout << x[i] << ' ' ;
    cout << endl;

    return 0; 
}