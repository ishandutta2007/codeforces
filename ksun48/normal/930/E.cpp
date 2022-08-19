#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MOD 1000000007
LL powmod(LL a, LL n){
    if(n == 0) return 1;
    if(n % 2) return (a*powmod(a,n-1)) % MOD;
    LL c = powmod(a, n/2);
    return (c*c) % MOD;
}
LL inv(LL a){
    return powmod(a, MOD-2);
}

vector<int> pos;


int idx(int v){
    int s = 0;
    int e = pos.size();
    while(s + 1 < e){
        int m = (s+e) / 2;
        if(pos[m] > v){
            e = m;
        } else {
            s = m;
        }
    }
    assert(pos[s] == v);
    return s;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    LL k, n, m;
    cin >> k >> n >> m;
    vector<pair<int,int> > ints;
    vector<int> whose;
    map<int,int> l;
    l[0] = 1;
    l[k] = 1;
    for(int i = 0; i < n+m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        l[a] = l[b+1] = 1;

        ints.push_back({a, b+1});
        whose.push_back((i < n));
    }
    for(auto x : l){
        pos.push_back(x.first);
    }
    LL g = pos.size() - 1;
    LL num0[g];
    LL num1[g];
    LL numB[g];
    for(int i = 0; i + 1 < pos.size(); i++){
        LL cnt = pos[i+1] - pos[i];
        num0[i] = num1[i] = 1;
        numB[i] = (powmod(2, cnt) - 2 + MOD) % MOD;
    }

    vector<int> conditions[2][g];

    for(int i = 0; i < n+m; i++){
        int a = idx(ints[i].first);
        int b = idx(ints[i].second);
        int w = whose[i];
        conditions[w][b-1].push_back(a);
    }
    LL dp01 = 1;
    vector<LL> dp0;
    vector<LL> dp1;
    int len0 = 0;
    int len1 = 0;
    LL sum0 = 0;
    LL sum1 = 0;
    for(int i = 0; i < g; i++){
        LL newdp01 = ( (sum0 + sum1 + dp01) % MOD ) * numB[i];
        newdp01 %= MOD;
        LL new0 = (dp01 + sum1) % MOD;
        LL new1 = (dp01 + sum0) % MOD;
        dp01 = newdp01;

        sum0 = (sum0 + new0) % MOD;
        dp0.push_back(new0); len0++;

        sum1 = (sum1 + new1) % MOD;
        dp1.push_back(new1); len1++;

        // if conditions, cut it off
        if(conditions[0][i].size() != 0){
            sort(conditions[0][i].begin(), conditions[0][i].end());
            int x = conditions[0][i][conditions[0][i].size()-1];
            int len = i - x + 1;
            while(len0 >= len){
                sum0 = (sum0 - dp0[dp0.size()-len0] + MOD) % MOD;
                len0--;
            }
        }
        if(conditions[1][i].size() != 0){
            sort(conditions[1][i].begin(), conditions[1][i].end());
            int x = conditions[1][i][conditions[1][i].size()-1];
            int len = i - x + 1;
            while(len1 >= len){
                sum1 = (sum1 - dp1[dp1.size()-len1] + MOD) % MOD;
                len1--;
            }
        }
        /*cout << dp01 << endl;
        for(int j = 1; j <= len0; j++){
            cout << dp0[j] << " ";
        }
        cout << endl;
        for(int j = 1; j <= len1; j++){
            cout << dp1[j] << " ";
        }
        cout << endl;
        cout << endl;*/
    }
    LL ans = (dp01 + sum0 + sum1) % MOD;
    cout << ans << endl;
}