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

const int N = 1500 + 100;
const ll base = 701;

map<vector<int>, int> mp;

ll ahash[N], bhash[N], chash[N];

vector<int> a[N], b[N], c[N];

int mark[N], sum[N], fix[N], rowVal[N]; 

vector<int> moves; 

int n, m;

void check() { 
    for(int i = 0; i < n; i++)
        if(ahash[i] != bhash[i])
            return;
    for(int i = 0; i < n; i++) 
        if(a[i] != b[i]) 
            return;
    reverse(moves.begin(), moves.end());
    cout << sz(moves) << endl;
    for(auto x: moves)
        cout << 1 + x << ' ';
    cout << endl;
    exit(0);
}

int tmp[N], newCol;

int cmp(int x, int y) { 
    if(rowVal[x] != rowVal[y])
        return rowVal[x] < rowVal[y];
    return ::a[x][newCol] < ::a[y][newCol];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m; 
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) { 
            int x;
            cin >> x;
            a[i].pb(x);
            ahash[i] = ahash[i] * base + x;
        }
        mp[a[i]]++;
    }
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) { 
            int x;
            cin >> x;
            b[i].pb(x);
            bhash[i] = bhash[i] * base + x;
        }
        mp[b[i]]--;
    }

    for(auto pp: mp)
        if(pp.second != 0) { 
            cout << -1 << endl;
            return 0;
        }

    for(int j = 0; j < m; j++) 
        for(int i = 1; i < n; i++) 
            if( b[i][j] < b[i-1][j] )
                sum[j]++;
    
    while(true) {
        check(); 
        bool found = false;
        for(int j = 0; j < m; j++) 
            if( !mark[j] && sum[j] == 0 ) {
                mark[j] = true;
                moves.pb(j);

                //sort
                for(int i = 0; i < n; i++) tmp[i] = i; 
                newCol = j;

                stable_sort(tmp, tmp + n, cmp);

                for(int i = 0; i < n; i++) {
                    c[i].swap(a[i]);
                    swap(ahash[i], chash[i]);
                }
                int lastRowVal = 0;
                for(int i = 0; i < n; i++) {
                    a[i].swap(c[tmp[i]]);
                    swap(ahash[i], chash[tmp[i]]);

                    rowVal[i] = max(rowVal[i], lastRowVal);
                    if(i && rowVal[i] == rowVal[i-1] && a[i][j] > a[i-1][j])
                        rowVal[i] = i;
                    lastRowVal = rowVal[i];
                }



                for(int i = 1; i < n; i++) 
                    if( !fix[i] && b[i][j] > b[i-1][j]) {
                        for(int k = 0; k < m; k++)
                            if( !mark[k] && b[i][k] < b[i-1][k] )
                                sum[k]--;
                        fix[i] = true;
                    }
                found = true;
                break;
            }
        if(!found)
            break;
    }

    cout << -1 << endl;


    return 0;
}