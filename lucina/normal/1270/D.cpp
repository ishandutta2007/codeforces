#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int a[nax], n, k;

pair<int, int> query(vector<int> & x){
    assert((int)x.size() == k);
    cout << "? ";
    for(int i : x)
        cout << i << ' ';
    cout << endl;
    int u, v;
    cin >> u; if(u == -1) throw;
    cin >> v;
    return make_pair(u, v);
}

vector<int> found, toAsk;
void ans(int x){
    cout << "! " << x << endl;
    exit(0);
}

void ans(){
    vector<int> tt;
    for(int i : found)
        tt.push_back(a[i]);
    sort(tt.begin(), tt.end());
    auto res = query(found);
    for(int j = 0 ;j < k; j ++){
        if(res.second == tt[j]){
            ans(j + 1);
        }
    }
    throw;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1 ;i <= k ; i++){
        toAsk.push_back(i);
    }
    int pt = k + 1;
    while((int)toAsk.size() == k){
        auto res = query(toAsk);
        vector<int> :: iterator todel;
        for(int j = 0 ; j < k ;j ++){
            if(toAsk[j] == res.first){
                todel = toAsk.begin() + j;
            }
        }
        found.emplace_back(*todel);
        a[*todel] = res.second;
        toAsk.erase(todel);
        if(pt <= n)
        toAsk.push_back(pt ++);
        if((int)found.size() == k){
            ans();
        }
    }
    int l = 0, r = 0;
    if((int)found.size() < 2) throw;
    int ma = max(a[found[0]], a[found[1]]);
    vector<int> s;
    while(l + found.size() + r < k){
        int del = toAsk[0];
        s.push_back(del);
        toAsk.erase(toAsk.begin()) ;
        toAsk.push_back(found[0]);
        toAsk.push_back(found[1]);
        auto res = query(toAsk);
        if(res.second == ma){
            l ++;
        }
        else r ++;
        toAsk.pop_back();
        toAsk.pop_back();
        toAsk.emplace_back(del);
    }
    vector<int> t;
    for(int j : found) t.push_back(a[j]);
    sort(t.begin(), t.end());
    for(int i : s) found.push_back(i);
    auto res = query(found);
    for(int j = 0 ; j < k ;j ++){
        if(res.second == t[j]){
            ans(l + j + 1);
        }
    }
}
/*
    Good Luck
        -Lucina
*/