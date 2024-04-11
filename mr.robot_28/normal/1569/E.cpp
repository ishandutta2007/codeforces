#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 2e5 + 100;
const int mod1 = 1e9 + 7;
const int mod = 998244353;
int k, A, h;
int pw[100];


int get_hash(vector <int> x){
    int s = 0;
    for(int i = 0; i < sz(x); i++){
        s = (s + pw[x[i]] * (i + 1)) % mod;
    }
    return s;
}
vector <int> evaluate(int mask, int n){
    int cur_place = n / 2 + 1;
    vector <int> mass(n);
    vector <int> p(n);
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
    int it = 0;
    while(sz(p) > 1)
    {
        vector <int> p1(n / 2);
        for(int i = 0; i < n; i += 2){
            if(mask & (1 << it)){
                mass[p[i + 1]] = cur_place;
                p1[i / 2] = p[i];
            }
            else{
                mass[p[i]] = cur_place;
                p1[i / 2] = p[i + 1];
            }
            it++;
        }
        p = p1;
        n /= 2;
        cur_place /= 2;
        cur_place++;
    }
    mass[p[0]] = 1;
    return mass;
}
void funct(vector <int> &p, bool winning){
    for(int i = 0; i < sz(p); i++){
        if(p[i] == 1){
            if(!winning){
                p[i]++;
            }
        }
        else{
            p[i] = 2 * p[i] - 1;
        }
    }
}
int get_hash(vector <int> &p, bool flag = 0, bool flag1 = 0, int it = 0){
    if(flag){
        funct(p, flag1);
    }
    int res = 0;
    for(int i = 0; i < sz(p); i++){
        res = (res + (it + i + 1) * pw[p[i]]) % mod;
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> A >> h;
    pw[0] = 1;
    for(int i = 1; i < 100; i++){
        pw[i] = pw[i - 1] * A % mod;
    }
    if(k <= 4){
        for(int i = 0; i < (1 << ((1 << k) - 1)); i++){
            vector <int> p = evaluate(i, 1 << k);
        /*    for(int j = 0; j < (1 << k); j++){
                cout << p[j] << " ";
            }
            cout << "\n";*/
            if(get_hash(p, 0, 0, 0) == h){
                for(int j = 0; j < (1 << k); j++){
                    cout << p[j] << " ";
                }
                return 0;
            }
        }
        cout << -1;
        return 0;
    }
    for(int c = 0; c < 2; c++){
        map <int, vector <int> > hash_left;
        for(int i = 0; i < 1 << 16; i++){
            vector <int> p = evaluate(i, 16);
            int hash_ = get_hash(p, true, c == 0, 0);
            hash_left[hash_] = p;
        }
        for(int i = 0; i < (1 << 16); i++){
            vector <int> p = evaluate(i, 16);
            int right_hash = get_hash(p, true, c == 1, 16);
            int h1 = (h + mod - right_hash) % mod;
            if(hash_left.count(h1)){
                for(auto x : hash_left[h1]){
                    cout << x << " ";
                }
                for(auto x : p){
                    cout << x << " ";
                }
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}