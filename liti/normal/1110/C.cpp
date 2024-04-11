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

map<int,int> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int z = 3;
    for(int i = 0; i < 25; i++) { 
        int best = z;

        for(int j = 2; j*j <= z; j++)
            if( z % j == 0 ) { 
                best = j; 
                break;
            }

        ans[z] = z/best;
        z = z * 2 + 1;
    }
   

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) { 
        int x;
        cin >> x; 
        try { 
            for(int j = 24; j >= 0; j--) 
                if( (x>>j) & 1 ) 
                    throw(j);
        } catch(int v) { 
            if( x == (1<<(v+1))-1 ) { 
                cout << ans[x] << endl;
            } else 
                cout << (1<<(v+1))-1 << '\n';
        }
    }
    return 0;
}