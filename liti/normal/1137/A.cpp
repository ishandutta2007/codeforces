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

const int N = 1000 + 10;

int a[N][N]; 

int ir[N][N], ic[N][N];
int er[N], ec[N]; 

pii r[N][N]; 
pii c[N][N]; 

int main(){
    ios::sync_with_stdio(false); cin.tie(0); 

    int n, m;
    cin >> n >> m; 

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) { 
            cin >> a[i][j]; 
            r[i][j] = {a[i][j], j}; 
            c[j][i] = {a[i][j], i}; 
        }

    for(int i = 0; i < n; i++) { 
        sort( r[i], r[i] + m ); 
        int last = -1; 
        int ind = -1; 
        for(int j = 0; j < m; j++) {
            if( r[i][j].F != last ) 
                ind++; 
            ir[i][r[i][j].S] = ind;
            last = r[i][j].F;
        }
        er[i] = ind+1; 
    }

    for(int j = 0; j < m; j++) { 
        sort( c[j], c[j] + n ); 
        int last = -1; 
        int ind = -1;
        for(int i = 0; i < n; i++) { 
            if( c[j][i].F != last ) 
                ind++; 
            ic[c[j][i].S][j] = ind; 
            last = c[j][i].F; 
        }
        ec[j] = ind+1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) { 
            int bef = max( ir[i][j] , ic[i][j] ); 
            int aft = max( er[i] - ir[i][j], ec[j] - ic[i][j] ); 
            cout << bef + aft << ' ';
        }
        cout << '\n';
    }
}