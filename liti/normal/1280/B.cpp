//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 60 + 5;

string a[N]; 
int row[2][N], col[2][N]; 

int gg(char ch) { 
    return ch == 'A'; 
}

void solve() {  
    memset(row, 0, sizeof row); 
    memset(col, 0, sizeof col); 

    int r, c; 
    cin >> r >> c; 
    bool hasP= false, hasA = false;
    for(int i = 0; i < r; i++) {
        cin>>a[i]; 
        for(int j = 0; j < c; j++) {  
            if( gg(a[i][j]) ) hasA = true; 
            else hasP = true; 
            row[gg(a[i][j])][i]++; 
            col[gg(a[i][j])][j]++; 
        }
    }

    if( !hasA ) { 
        cout << "MORTAL" << '\n';
        return;
    }
    if( !hasP ) { 
        cout << 0 << '\n';
        return;
    }

    if( row[0][0] == 0 || row[0][r-1] == 0  || col[0][0] == 0 || col[0][c-1] == 0  ) { 
        cout << 1 << '\n';
        return; 
    }

    if( row[1][0] == 0 && row[1][r-1] == 0 && col[1][0] == 0 && col[1][c-1]  ==  0 ) {  
        cout << 4 << '\n';
        return; 
    }

    bool is2 = false; 
    is2 |= gg(a[0][0]) || gg(a[r-1][0]) || gg(a[0][c-1]) || gg(a[r-1][c-1]); 
    for(int i = 0; i < r;  i++) 
        is2 |= (row[0][i]  == 0);
    for(int j = 0; j < c;  j++) 
        is2 |= (col[0][j]  == 0);

    if( is2 ) { 
        cout << 2 <<'\n';
        return;
    }
    cout << 3 << '\n'; 
}

int main() {
    int  t; 
    cin >> t; 
    while(t--)
        solve();
    return 0;
}