#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define ld      long double
#define pii     pair<int ,int>
#define pld     pair<ld ,ld>
#define F       first
#define S       second
#define mod     1000000007
#define pb      push_back
#define mp      make_pair
#define all(x)  x.begin(),x.end()
#define mset(x) memset(x, 0, sizeof(x));
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1000;

int n, grid[N][N];
void run(){
    cin >> n;
    int fill = 0;
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++){

            grid[i][j]              = 4*fill + 1;  
            grid[i][j + n/2]        = 4*fill + 2;   
            grid[i + n/2][j]        = 4*fill + 3;   
            grid[i + n/2][j + n/2]  = 4*fill;       
            
            fill++;

        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

signed main(){
    int tests = 1;
    // cin >> tests;
    for(int i = 1; i <= tests; i++) run();
    return 0;
}