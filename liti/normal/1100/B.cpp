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

const int N = 100 * 1000 + 10;

int cnt[N];
set<pii> curr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n, m;
    cin >> n >> m; 
    for(int i = 0 ; i < n; i++) 
        curr.insert( {0, i} ); 

    int req = 1;
    string res = "";
    for(int i = 0; i < m; i++) { 
        int v;
        cin >> v;
        v--; 
        curr.erase( {cnt[v],v} );
        cnt[v]++;
        curr.insert( {cnt[v],v} );

        if( curr.begin()->first == req ) { 
            req++;
            res += "1";
        } else
            res += "0";
    }

    cout << res << endl;


    return 0;
}