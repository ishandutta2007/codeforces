#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1000000007;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int> > v(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        v[i].first = (s == "ACCEPT");
        cin >> v[i].second;
    }
    set<int> buys;
    set<int> unknown;
    set<int> sells;
    buys.insert(-1);
    sells.insert(400000000);
    int ans = 1;
    for(int j = 0; j < n; j++){
        int z = v[j].second;
        if(v[j].first == 1){
            if(unknown.find(z) != unknown.end()){
                ans = (ans + ans) % MOD;
                for(int v : unknown){
                    if (v < z){
                        buys.insert(v);
                    } else if(v > z){
                        sells.insert(v);
                    } else {
                        // do nothing
                    }
                }
                unknown.clear();
            } else if(buys.find(z) != buys.end()){
                if(*buys.rbegin() != z){
                    ans = 0;
                    break;
                }
                buys.erase(z);
                for(int v : unknown){
                    sells.insert(v);
                }
                unknown.clear();
            } else if(sells.find(z) != sells.end()){
                if(*sells.begin() != z){
                    ans = 0;
                    break;
                }
                sells.erase(z);
                for(int v : unknown){
                    buys.insert(v);
                }
                unknown.clear();
            }
        } else {
            if(z > *sells.begin()){
                sells.insert(z);
            } else if(z < *buys.rbegin()){
                buys.insert(z);
            } else {
                unknown.insert(z);
            }
        }
    }
    int realans = ans;
    for(int i = 0; i < unknown.size(); i++){
        realans = (ans + realans) % MOD;
    }
    cout << realans << endl;
}