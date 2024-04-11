#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 2e5 + 100;
const int mod1 = 1e9 + 7;
const int mod = 998244353;
int a[N], b[N];
int Tree[4 * N][2][2];
int mass[2][2], mass1[2][2];
void build(int v, int l, int r){
    if(l == r){
        int d = b[l] - a[l];
        if(d > 0){
            Tree[v][0][0] = d;
        }
        else{
            Tree[v][1][1] = -d;
        }
        return;
    }
    build(v * 2, l, (l + r) / 2);
    build(v * 2 + 1, (r + l) / 2 + 1, r);
    for(int j = 0; j < 2; j++){
        for(int k = 0; k < 2; k++){
            mass[j][k] = Tree[v * 2][j][k];
            mass1[j][k] = Tree[v * 2 + 1][j][k];
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            int j1 = 1 - j;
            for(int k = 0; k < 2; k++){
                int e;
                Tree[v][i][k] += e = min(mass[i][j], mass1[j1][k]);
                mass[i][j] -= e;
                mass1[j1][k] -= e;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            Tree[v][i][j] += mass[i][j] + mass1[i][j];
        }
    }
}
vector <vector <int> > ans(int v, int l, int r, int al, int ar){
    vector <vector <int> > res(2, vector <int> (2));
    if(l >= al && r <= ar){
        for(int i = 0;i < 2; i++){
            for(int j = 0; j< 2; j++){
                res[i][j] = Tree[v][i][j];
            }
        }
        return res;
    }
    if(l <= ar && r >= al){
        vector <vector <int> > res1 = ans(v * 2, l, (r + l) / 2, al, ar);
        vector <vector <int> > res2 = ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
        for(int i = 0; i < 2; i++){
            for(int j = 0; j< 2; j++){
                int j1 = 1 - j;
                for(int k = 0; k < 2; k++){
                    int e = min(res1[i][j], res2[j1][k]);
                    res1[i][j] -= e;
                    res2[j1][k] -= e;
                    res[i][k] += e;
                }
            }
        }
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                res[i][j] += res1[i][j] + res2[i][j];
            }
        }
        return res;
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    build(1, 0, n - 1);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        vector <vector <int> > res = ans(1, 0, n - 1, l, r);
        if(res[1][0] != 0 || res[0][0] != 0 || res[1][1] != 0){
            cout << -1 << "\n";
        }
        else{
            cout << res[0][1] << "\n";
        }
    }
    return 0;
}