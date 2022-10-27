#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
const int N = 500;
const int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    vector <int> pref(m + 1);
    vector <int> last(n, -1);
    int T = sqrt(n) + 10;
    vector <vector <int> > add(T, vector <int> (T));
    vector <int> ans(m);
    vector <int> startx(n);
    for(int i = 0; i < m; i++){
        int op, k;
        cin >> op >> k;
        k--;
        if(x[k] + y[k] >= T){
            if(op == 1){
                last[k] = i;
            }
            else{
                int j = last[k];
                while(j + x[k] + y[k] - 1 < i){
                    pref[j + x[k] + y[k]]--;
                    pref[j + x[k]]++;
                    j += x[k] + y[k];
                }
                if(j + x[k] < i){
                    pref[j + x[k]]++;
                    pref[i]--;
                }
                last[k] = -1;
            }
        }
        else{
            int t = x[k] + y[k];
            int d = 1;
            if(op == 2){
                d = -1;
            }
            else{
                startx[k] = i;
            }
            for(int j = 0; j < y[k]; j++){
                add[t][(startx[k] + x[k] + j) % t] += d;
            }
        }
        for(int j = 1; j < T; j++){
            ans[i] += add[j][i % j];
        }
    }
    for(int i = 0; i < n; i++){
        if(last[i] != -1){
            int j = last[i];
            while(j + x[i] + y[i] - 1 < m){
                pref[j + x[i] + y[i]]--;
                pref[j + x[i]]++;
                j += x[i] + y[i];
            }
            if(j + x[i] < m){
                pref[j + x[i]]++;
            }
        }
    }
    int s = 0;
    for(int i = 0; i < m; i++){
        s += pref[i];
        cout << s + ans[i] << "\n";
    }
    return 0;
}