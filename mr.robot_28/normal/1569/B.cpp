#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 1e5 + 100;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector <vector <int> > a(n, vector <int> (n, -1));
        vector <int> vec;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                for(int j = 0; j < n; j++){
                    if(i == j){
                        continue;
                    }
                    a[i][j] = a[j][i] = 0;
                }
            }
            else{
                vec.push_back(i);
            }
        }
        if(sz(vec) == 1 || sz(vec) == 2){
            cout << "NO\n";
            continue;
        }
        for(int i = 0; i < sz(vec); i++)
        {
            int i1 = (i + 1) % sz(vec);
            int x = vec[i];
            int y = vec[i1];
            a[x][y] = 2;
            a[y][x] = 1; 
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    cout << "X";
                }
                else if(a[i][j] == 1){
                    cout << "+";
                }
                else if(a[i][j] == 2){
                    cout << "-";
                }
                else{
                    cout << "=";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}