#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> solve(vector<int> a, vector<int> b, int bit){
    int n = a.size();

    // a ^ perm(b)
    if(bit < 0 || n == 0){
        return a;
    }
    if(n == 1){
        return {a[0] ^ b[0]};
    }
    vector<int> newb[2];
    vector<int> newa[2];
    for(int i = 0; i < n; i++){
        int c = (b[i] >> bit);
        newb[c].push_back(b[i] ^ (c << bit));
    }
    vector<int> assign(n);
    for(int i = 0; i < n; i++){
        int c = (a[i] >> bit);
        int z;
        if(newa[c].size() < newb[c].size()){
            z = c;
        } else {
            z = 1^c;
        }
        newa[z].push_back(a[i] ^ (c << bit));
        assign[i] = z;
    }
    vector<int> ans[2];
    ans[0] = solve(newa[0], newb[0], bit-1);
    ans[1] = solve(newa[1], newb[1], bit-1);

    vector<int> realans(n);
    int idx[2]; idx[0] = idx[1] = 0;
    for(int i = 0; i < n; i++){
        int zz;
        zz = ans[assign[i]][idx[assign[i]]];
        idx[assign[i]]++;
        int c = (a[i] >> bit);
        zz ^= ((c ^ assign[i]) << bit);
        realans[i] = zz;
    }
    return realans;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<int> ans = solve(a, b, 30);
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}