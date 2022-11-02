#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

#define ll long long
#define F first
#define S second

struct goods {
       long long s, nn;
       goods(ll a = 0, ll b = 0): s(a), nn(b) {}
};

bool cmp(goods a, goods b) {
     return a.s < b.s;
}; 

int main() {
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    vector<goods> t, p;
    for(int i = 0; i < n; ++i) {
            int c, v;
            cin >> c >> v;
            if(v == 1)
                 t.push_back(goods(c, i + 1));
            else
                p.push_back(goods(c, i + 1));
    }
    n = k;
    sort(t.begin(), t.end(), cmp);
    sort(p.begin(), p.end(), cmp);
    double res = 0;
    ll pt = (ll)t.size() - 1, pp = (ll)p.size() - 1;
    vector<vector<ll> > ans(n);
    --n;
    for(;n >= 0;--n) {
            vector<ll> cur;
            if(pt >= 0) {
                  ll mn = t[pt].s, all = 0;
                  if(n) {
                        all = t[pt].s;
                        cur.push_back(t[pt].nn);
                  }
                  else {
                       while(pt >= 0) {
                                all += t[pt].s;
                                mn = min(mn, t[pt].s);
                                cur.push_back(t[pt].nn);
                                --pt;
                       }   
                       pt = -1;
                  }   
                  while(pp >= 0 && (n == 0 || p[pp].s > t[pt].s) && (n == 0 || pt + pp >= n)) {
                           mn = min(mn, p[pp].s);
                           all += p[pp].s;
                           cur.push_back(p[pp].nn);
                           --pp;
                  }
                  res += (double)all - (double)mn / 2.0;
                  --pt;
            }
            else {
                 while(pp >= n) {
                          res += (double)p[pp].s;
                          cur.push_back(p[pp].nn);
                          --pp;
                 }
            }
            ans[n] = cur;
    }
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << res << endl;
    for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i].size() << " ";
            for(int j = 0; j < ans[i].size(); ++j)
                    cout << ans[i][j] << " ";
            cout << endl;
    }
    cin >> n;
    return 0;
}