#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;

const int N = 5e5 + 100;
const int T = 350;
const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <vector <int> > a(n);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    int m;
    cin >> m;
    vector <vector <int> > nt(m);
    map <vector <int>, int> mp;
    for(int i = 0; i < m; i++){
        vector <int> v;
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            x--;
            nt[i].push_back(x);
            v.push_back(x);
        }
        mp[v] = 1;
    }
    vector <int> res(n);
    int ans = 0;
    vector <int> v1(n);
    for(int i = 0; i < n; i++){
        v1[i] = sz(a[i]) - 1;
    }
    if(!mp.count(v1)){
        int s = 0;
        for(int i = 0; i < n; i++){
            s += a[i][sz(a[i]) - 1];
        }
        if(s > ans){
            ans = s;
            for(int i = 0; i < n; i++){
                res[i] = sz(a[i]) - 1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            bool fl = 1;
            for(int k = 0; k < n; k++){
                if(k != j){
                    v1[k] = nt[i][k];
                }
                else{
                    v1[k] = nt[i][k] - 1;
                    if(v1[k] == -1){
                        fl = 0;
                    }
                }
            }
            if(fl && !mp.count(v1)){
                int s = 0;
                for(int k = 0; k < n; k++){
                    s += a[k][v1[k]];
                }
                if(s > ans){
                    ans = s;
                    for(int k = 0; k < n; k++){
                        res[k] = v1[k];
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << res[i] + 1 << " ";
    }
    return 0;
}