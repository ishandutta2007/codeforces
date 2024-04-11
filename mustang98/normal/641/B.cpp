#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

#define F first
#define S second
#define x1 privet1
#define x2 privet2
#define y1 privet3
#define y2 privet4
#define hash privet5

using namespace std;

    const int inf = 111111111;

    int n, m, k, a[111][111];
    pair<pair<int, int>, pair<int, int> > b[11111];

    void circle(int x, int y){
        if(x == 1){
            int k = a[y-1][m-1];
            for(int i=m-1; i>0; i--) a[y-1][i] = a[y-1][i-1];
            a[y-1][0] = k;
        } else {
            int k = a[n-1][y-1];
            for(int i=n-1; i>0; i--) a[i][y-1] = a[i-1][y-1];
            a[0][y-1] = k;
        }
    }

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) for(int q=0; q<m; q++) a[i][q] = inf;
    for(int i=0; i<k; i++){
        cin >> b[i].F.F;
        if(b[i].F.F <3) cin >> b[i].F.S; else cin >> b[i].S.F >> b[i].S.S >> b[i].F.S;
    }
    for(int i=k-1; i>=0; i--){
        if(b[i].F.F != 3) circle(b[i].F.F, b[i].F.S); else a[b[i].S.F-1][b[i].S.S-1] = b[i].F.S;
    }
    for(int i=0; i<n; i++){
        for(int q=0; q<m; q++)
            if(a[i][q] == inf) cout << "1 "; else cout << a[i][q] << " ";
        cout << "\n";
    }
}