#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

char solve(int numb1, int numa1, int numb2, int numa2){
    if(numb2 < numb1) return '0';
    if(numa1 < numa2) return '0';
    if((numb1 % 2) != (numb2 % 2)) return '0';
    if(numb1 == numb2){
        if(numa1 % 3 == numa2 % 3) return '1';
        return '0';
    }
    if(numb1 == 0 && numa1 == numa2) return '0';
    return '1';
}

string ans;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    string s[2];
    cin >> s[0] >> s[1];
    vector<int> bsums[2];
    bsums[0].push_back(0);
    bsums[1].push_back(0);
    vector<int> numa[2];
    for(int z = 0; z < 2; z++){
        int cur = 0;
        for(int i = 0; i < s[z].size(); i++){
            bsums[z].push_back(bsums[z][i] + (s[z][i] != 'A') );
            if(s[z][i] == 'A'){
                cur++;
            } else {
                cur = 0;
            }
            numa[z].push_back(cur);
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        int numb1 = bsums[0][b+1] - bsums[0][a];
        int numb2 = bsums[1][d+1] - bsums[1][c];
        int numa1 = min(b-a+1, numa[0][b]);
        int numa2 = min(d-c+1, numa[1][d]);
        ans += solve(numb1, numa1, numb2, numa2);
    }
    cout << ans << endl;
}