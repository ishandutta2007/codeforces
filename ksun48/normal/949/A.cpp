#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int diff = 0;
    int ok = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            diff++;
        } else {
            diff--;
        }
    }
    if(diff <= 0){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < diff; i++){
        s += '1';
    }

    int dx = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            dx++;
        } else {
            dx--;
        }
        if(dx < 0 || dx > diff){
            cout << -1 << endl;
            return 0;
        }
    }
    set<int> ones;
    set<int> zeroes;
    vector<int> seq[diff];
    for(int i = 0; i < diff; i++){
        ones.insert(i);
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            int a = *ones.begin();
            seq[a].push_back(i);
            ones.erase(a);
            zeroes.insert(a);
        } else {
            int a = *zeroes.begin();
            seq[a].push_back(i);
            zeroes.erase(a);
            ones.insert(a);
        }
    }
    cout << diff << '\n';
    for(int i = 0; i < diff; i++){
        cout << seq[i].size();
        for(int j = 0; j < seq[i].size(); j++){
            cout << ' ' << seq[i][j] + 1;
        }
        cout << '\n';
    }
}