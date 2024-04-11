#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> moves;
vector<int> shift(vector<int> a, int k){
    assert(k >= 0 && k <= a.size());
    moves.push_back(k);
    vector<int> b;
    for(int j = 0; j < k; j++){
        b.push_back(a[a.size()-1-j]);
    }
    for(int j = 0; j < a.size()-k; j++){
        b.push_back(a[j]);
    }
    /*for(int j = 0; j < a.size(); j++){
        cout << b[j] << " ";
    }
    cout << endl;*/
    return b;
}
int main(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string ss = s;
    string tt = t;
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());
    if(ss != tt){
        cout << -1 << endl;
        return 0;
    }
    vector<int> used(n, 0);

    vector<int> cur;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(s[j] == t[i] && !used[i]){
                used[i] = 1;
                cur.push_back(i);
                break;
            }
        }
    }
    vector<int> perm(n,0);
    for(int j = 0; j < n; j++){
        perm[j] = j;
    }

    vector<int> rperm = perm;
    reverse(rperm.begin(), rperm.end());

    while(1){
        int gg = 1;
        for(int j = 0; j < cur.size(); j++){
            if(cur[j] != j) gg = 0;
        }
        if(gg) break;

        if(cur == rperm){
            cur = shift(cur, n);
            continue;
        }

        int done = 0;
        for(int j = 1; j < n; j++){
            if(abs(cur[j] - cur[j-1]) == 1){
                continue;
            }
            if(abs(cur[j] - cur[0]) == 1){
                cur = shift(cur, n-j);
                done = 1;
                break;
            }
        }
        if(done) continue;
        for(int j = 0; j < n; j++){
            if(j > 0 && j < n-1 && abs(cur[j] - cur[j-1]) == 1 && abs(cur[j] - cur[j+1]) == 1){
                continue;
            }
            for(int i = j+2; i < n; i++){
                if(abs(cur[j] - cur[i]) != 1) continue;
                if(j > 0 && abs(cur[j] - cur[j-1]) == 1) continue;
                if(i + 1 < n && abs(cur[i] - cur[i+1]) == 1) continue;
                done = 1;
                cur = shift(cur, n-1-i);
                for(int z = n-1; z > 0; z--){
                    if(abs(cur[z] - cur[z-1]) != 1){
                        cur = shift(cur, n-z);
                        break;
                    }
                }
                break;
            }
            if(done) break;
        }
        if(done) continue;
        for(int j = 0; j < n; j++){
            if(j > 0 && j < n-1 && abs(cur[j] - cur[j-1]) == 1 && abs(cur[j] - cur[j+1]) == 1){
                continue;
            }
            for(int i = j+2; i < n; i++){
                if(abs(cur[j] - cur[i]) != 1) continue;
                if(i + 1 < n && abs(cur[i] - cur[i+1]) == 1) continue;
                if(j + 1 < n && abs(cur[j] - cur[j+1]) == 1) continue;
                done = 1;
                cur = shift(cur, n-1-j);
                for(int z = n-1; z > 0; z--){
                    if(abs(cur[z] - cur[z-1]) != 1){
                        cur = shift(cur, n-z);
                        break;
                    }
                }
                break;
            }
            if(done) break;
        }
        if(done) continue;
        cur = shift(cur, n);
    }
    assert(moves.size() <= 6100);
    cout << moves.size() << '\n';
    for(int j = 0; j < moves.size(); j++){
        cout << moves[j] << " ";
    }
    cout << '\n';
}