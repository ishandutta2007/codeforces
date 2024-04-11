#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> used(n, 0);
    int p = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            used[i] = 1;
            p++;
        }
        if(p == k/2) break;
    }
    p = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == ')'){
            used[i] = 1;
            p++;
        }
        if(p == k/2) break;
    }
    string t;
    for(int i = 0; i < n; i++){
        if(used[i]){
            t += s[i];
        }
    }
    cout << t << '\n';
}