
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// there is some interval between best sell and best buy
// each price has a time interval where it exists
// at any moment in time, all buy offers less than all sell offers
// when a node is accepted, everything above it must be sell and everything below it must be buy

// for a given price, is it buy? find maximum/minimum accepted prices on the interval where it's live
// then it's just segment tree

// if min accepted price < p => p is sell
// if max accepted prices > p => p is buy
// if both, answer is 0, else, can be either

const int N = 363310, M = 1e9 + 7;
int n, p;
string s;
set<int> se, se3;
set<int, greater<int>> se2;
map<int, vector<int>> buyedge, selledge;
set<int> buy, sell;

int dfs(int x) {
    int cnt = 1;
    sell.insert(x);
    for(int y : selledge[x]) {
        if(buy.count(y) == 0 && sell.count(y) == 0) {
            cnt += dfs(y);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> s >> p;
        if(s == "ACCEPT") {
            se.erase(p);
            se2.erase(p);
            auto it = se.lower_bound(p);
            auto it2 = se2.lower_bound(p);
            if(it != se.end()) {
                sell.insert(*it);
            }
            if(it2 != se2.end()) {
                buy.insert(*it2);
            }
        }else {
            auto it = se.lower_bound(p);
            auto it2 = se2.lower_bound(p);
            if(it != se.end()) {
                selledge[p].push_back(*it);
                buyedge[*it].push_back(p);
            }
            if(it2 != se2.end()) {
                selledge[*it2].push_back(p);
                buyedge[p].push_back(*it2);
            }
            se.insert(p);
            se2.insert(p);
            se3.insert(p);
        }
    }
    ll ans = 1;
    queue<int> Q;
    for(int x : buy) Q.push(x);
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int y : buyedge[x]) {
            if(buy.count(y) == 0) {
                buy.insert(y);
                Q.push(y);
            }
        }
    }
    for(int x : sell) Q.push(x);
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int y : selledge[x]) {
            if(sell.count(y) == 0) {
                sell.insert(y);
                Q.push(y);
            }
        }
    }
    for(int p : se3) {
        int cnt = buy.count(p) + sell.count(p);
        if(cnt == 0) {
            ans = (ans * (dfs(p) + 1)) % M;
        } else if(cnt == 2) {
            cout << "0\n";
            return 0;
        }
    }
    cout << ans << '\n';
}