#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
const int N = 500;
const int mod = 1e9 + 7;
int pref[N][N];
int get(int x, int y, int x1, int y1){
    return pref[x1][y1] - pref[x - 1][y1] - pref[x1][y - 1] + pref[x - 1][y - 1];
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector <string> str(n);
        for(int i = 0; i < n; i++){
            cin >> str[i];
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                pref[i][j] = 0;
                if(i != 0 &&  j != 0){
                    pref[i][j] = (str[i - 1][j - 1] == '1');
                    pref[i][j] -= pref[i - 1][j - 1];
                }
                if(i != 0){
                    pref[i][j] += pref[i - 1][j];
                }
                if(j != 0){
                    pref[i][j] += pref[i][j - 1];
                }
            }
        }
        int minres = 1e9;
        for(int x1 = 1; x1 <= n; x1++){
            for(int x2 = x1 + 4; x2 <= n; x2++){
                int s = 0;
                int mina = 1e9;
                for(int i = 1; i <= m; i++){
                    if(i != 1){
                        s += get(x1 + 1, i - 1, x2 - 1, i - 1);
                    }
                    int s1 = s + ((x2 - x1 - 1) - get(x1 + 1, i, x2 - 1, i));
                    if(i != 1){
                        s1 += i - 1 - get(x1, 1, x1, i - 1);
                        s1 += i - 1 - get(x2, 1, x2, i - 1);
                    }
                    minres = min(minres, s1 + mina);
                    if(i >= 3){
                        int j = i - 2;
                        int cur = -(s - get(x1 + 1, i - 1, x2 - 1, i - 1) - 
                            get(x1 + 1, i - 2, x2 - 1, i - 2));
                      //  cout << cur << " ";
                        cur += - get(x1 + 1, j, x2 - 1, j) + (x2 - x1 - 1 - get(x1 + 1, j, x2 - 1, j));
                        cur -= j - get(x1, 1, x1, j);
                        cur -= j - get(x2, 1, x2, j);
                        mina = min(mina, cur);
                    }  
                 //  cout << minres << "\n";
                }
               // cout << x1 << " " << x2 << " " << minres << "\n";
            }
        }
        cout << minres << "\n";
    }
    return 0;
}