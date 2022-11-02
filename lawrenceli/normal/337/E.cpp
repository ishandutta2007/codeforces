#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;

const int MAXN = 10;

int n;
ll a[MAXN];
map<ll, int> fact[MAXN];
int par[MAXN];
int best=1e9;
vector<int> childs[MAXN];
bool prime[MAXN];
map<ll, int> mp;

void check() {
    int nroot=0;
    for (int i=0; i<n; i++) childs[i].clear();
    for (int i=0; i<n; i++) {
        if (par[i]==-1) nroot++;
        else childs[par[i]].push_back(i);
    }
    int num=n;
    if (nroot>1) num++;
    for (int i=0; i<n; i++) {
        if (prime[i]) num--;
        mp.clear();
        for (int j=0; j<childs[i].size(); j++) {
            int k=childs[i][j];
            for (typeof(fact[k].begin()) it=fact[k].begin(); it!=fact[k].end(); it++) mp[it->first] += it->second;
        }
        for (typeof(mp.begin()) it=mp.begin(); it!=mp.end(); it++) {
            if (it->second > fact[i][it->first]) return;
        }
        for (typeof(fact[i].begin()) it=fact[i].begin(); it!=fact[i].end(); it++) {
            num += it->second - mp[it->first];
        }
    }
    best = min(best, num);
}

void dfs(int m) {
    if (m==n) {
        check();
    }
    else {
        for (int i=-1; i<m; i++) {
            par[m]=i;
            dfs(m+1);
        }
    }
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n); reverse(a, a+n);
    for (int i=0; i<n; i++) {
        ll k=2, m=a[i], x=sqrt(m)+2;
        while (m>1 && k<=x) {
            if (m%k==0) {
                m/=k;
                fact[i][k]++;
            }
            else k++;
        }
        if (m>1) fact[i][m]++;
        if (fact[i].size()==1 && fact[i].begin()->second==1) prime[i]=1;
    }
    dfs(0);
    cout << best << endl;
}