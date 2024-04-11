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

const int N = 4 * 1000 * 100 + 100;

map<int,int> cnt; 

vector<int> num[N]; 

vector<int> a[N]; 

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 

    int n; 
    cin  >> n;

    for(int i = 0; i < n; i++)  { 
        int x; 
        cin >> x; 
        cnt[x]++; 
    }

    for(auto item: cnt) 
        num[item.S].pb(item.F); 

    int sum = 0; 
    int ans = 0; 
    int sans = 0; 
    int currDiff = 0; 
    for(int i = 1; i < N; i++) { 
        currDiff += sz(num[i]); 
        sum += i * sz(num[i]);
        int val = sum + (sz(cnt)-currDiff) * i;
        val = (val / i) * i;
        if( val >= max(ll(sans), 1ll*i*i) ) { 
            ans = i; 
            sans = val; 
        }
    }

    int row = ans; 
    int col = sans / row; 

    cout << row * col << endl << row << " " << col << endl; 

    for(int i = row + 1; i < N;  i++) 
        for(auto x: num[i])
            num[row].pb(x); 

    for(int i = 0; i < row; i++) 
        a[i].resize(col); 

    int i = 0, j = 0; 
    int s = 0;
    int done = row * col; 
    for(int t = row; t >= 0; t--) { 
        for(auto x : num[t])  { 
            for(int times = 0; times < t; times++) { 
                if( done ) {  
                    done--;
                 //   cout<< i << " " << j << "  " << t << " " << x  << endl;
                    a[i][j] = x;
                    i++;
                    if( i == row ) {  
                        i =  0; 
                        j = ++s; 
                    } else {
                        j++;
                        if( j == col ) 
                            j = 0; 
                    }
                }
            }
        }
    }

    for(int i = 0 ; i < row ; i++) {
        for( int j = 0 ; j < col ; j++) 
            cout << a[i][j] << ' '; 
        cout<< '\n';
    }

    return 0;
}