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

const int maxN = 300 + 10;

int n, t;

int s[maxN];
int x[maxN];
int tot;

int get(int l, int r) {
    cout << "? " << l << " " << r << endl;
    fflush(stdout); 
    int nt;
    cin >> nt;
    return nt;
}

int getZ() { 
    while(true) {
        int v = get(2, n); 
        if( v == n - t ) { 
            tot ^= 1; 
            t = v; 
        } else { 
            tot ^= 1;
            x[0] ^= 1;


            if( 1 + (n-1) - (t-1) == v ) {
                t = v;
                return 1; 
            }
            t = v;
            return 0;
        }
    }
}

int main() {
    cin >> n >> t; 

    if( n == 1 ) { 
        cout << "! " << t << endl;
        fflush(stdout);
        return 0;
    }

    s[0] = getZ();
    s[0] ^= tot ^ x[0];
    //cerr << "~~~ " << s[0] << " " << tot << " " << x[0] << endl;

    for(int i = 1; i < n; i++) { 
        while(true) { 
            int pt = t;
            int yek = 0; 
            int xi = x[i], ti = tot;

            for(int j = 0; j < i; j++) 
                if( s[j] ^ x[j] ^ tot == 1 ) 
                    yek ++;

            int nt = t = get(i+1, i + 1); 
            //cerr << tot << " " << x[0] << endl;
            int v = getZ();
            //cerr << "## " << v << " " << tot << " " << x[0] << ", " << yek << endl;
            if( v ^ tot ^ x[0] == s[0] ) 
                for( int j = i; j < n; j++ ) 
                    x[j] ^= 1;
            else { 
                for(int j = 0; j <= i; j++)
                    x[j] ^= 1;
                if( pt - yek + i - yek + 1 == nt ) 
                    s[i] = xi ^ ti;//
                else
                    s[i] = xi ^ ti ^ 1;
                //cerr << "~ " << i << ' ' << s[i] << endl;
                break;
            }
        }
    }

    string ans = "";
    for(int i = 0; i < n; i++)
        if( s[i] == 0 ) 
            ans += "0";
        else
            ans += "1";

    cout << "! " << ans << endl;
    fflush(stdout);

    return 0; 
}