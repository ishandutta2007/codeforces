#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
using namespace std;

const int N = 5e5 + 100;
const int T = 350;
const int mod = 998244353;
int power(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        int t = power(a, b / 2);
        return t * t % mod;
    }
    return a * power(a, b - 1) % mod;
}
signed main() {
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int cn[n][2];
    int cm[m][2];
    vector<int> d1(n), d2(m);
    for(int x = 0; x < 2; x++){
        for(int i = 0; i < n; i++){
                cn[i][x] = 0;
            }
            for(int i = 0; i < m; i++){
                cm[i][x] = 0;
            }
    }
    map <pair <int, int>, int> cl;
    int k1 = 0, k2 = 0;
    int c1 = n, c2 = m;
    vector <int> p(2);
 //   cout << k << "\n";
    for(int i = 0; i < k; i++){
        int t, x, y;
        cin >> x >> y >> t;
        x--;
        y--;
        int f = -1;
        if(cl.count({x, y})){
        if(cl[{x, y}] == 0){
            f = 0;                
        }
        else if(cl[{x, y}] == 1){
            f = 1;
        }
        }
        if(f != -1){
     //       cout << "Err\n";
            d1[x]--;
            d2[y]--;
            p[((x + y) % 2) ^ f]--;
            if(d1[x] == 0){
                c1++;
            }
            if(d2[y] == 0)
            {
                c2++;
            }
            if(cn[x][((x + y) % 2) ^ f] == 1 && cn[x][f ^ 1 ^ ((x + y) % 2)] != 0)
            {
                k1--;
            }
            cn[x][((x + y) % 2) ^ f]--;
            if(cm[y][(x + y) % 2 ^ f] == 1 && cm[y][f ^ 1 ^ ((x + y) % 2)] != 0)
            {
                k2--;
            }
            cm[y][((x + y) % 2) ^ f]--;
            cl.erase({x, y});
        }
        if(t == 0)
        {
            cl[{x, y}] = 0;
        }
        else if(t == 1){
            cl[{x, y}] = 1;
        }
        f = t;
        if(f != -1){
       //    cout << "Add\n";
            p[((x + y) % 2) ^ f]++;
            d1[x]++;
            d2[y]++;
            if(d1[x] == 1){
                c1--;
            }
            if(d2[y] == 1){
                c2--;
            }
            if(cn[x][((x + y) % 2) ^ f] == 0 && cn[x][f ^ 1 ^ ((x + y) % 2)] != 0)
            {
                k1++;
            }
            cn[x][((x + y) % 2) ^ f]++;
            if(cm[y][((x + y) % 2) ^ f] == 0 && cm[y][f ^ 1 ^ ((x + y) % 2)] != 0)
            {
                k2++;
            }
            cm[y][((x + y) % 2) ^ f]++;
        }
        //cout << k1 << " " << k2 << " " << c1 << " " << c2 << "\n";
        if(k1 == 0 && k2 == 0){
            cout << (power(2, c1) + power(2, c2) - (p[0] == 0 || p[1] == 0) - (c1 == n && c2 == m) + mod) % mod << "\n";
        }
        else if(k1 == 0){
            cout << power(2, c1) % mod << "\n";
        }
        else if(k2 == 0)
        {
            cout << power(2, c2) % mod << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
    return 0;
}