#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

const int inf = (int)1e9;
const ll md = (ll)1e9 + 7, inf64 = (ll)1e18;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int lneed = 0, rneed = -1, sum = 0;
    vector< vector<int> > a(n);
    for(int i = 0; i < n; i++){
        int sz;
        cin >> sz;
        a[i].resize(sz);
        for(int j = 0; j < sz; j++)
            cin >> a[i][j];
        sum += sz;
    }

    lneed = rneed = sum / n;
    if(sum % n != 0) rneed++;
    vector< pair<set<int>, int> > lft, rht;

    vector< pair<set<int>, int> > finl, finr;
    vector< pair<int, pair<int, int> > > ans;
    for(int i = 0; i < n; i++){
        set<int> s;
        for(int j : a[i])
            s.insert(j);
        if((int)a[i].size() < lneed){
            lft.push_back({s, i});
        }
        if((int)a[i].size() == lneed){
            finl.push_back({s, i});
        }
        if((int)a[i].size() > rneed){
            rht.push_back({s, i});
        }
        if((int)a[i].size() == rneed){
            finr.push_back({s, i});
        }
    }


    while(!lft.empty() && !rht.empty()){

        set<int> ws;

        auto& ll = (lft.back()).first;
        auto& rr = (rht.back()).first;
        int x1 = ll.size();
        int x2 = rr.size();

        for(int i : ll){
            if(rr.find(i) != rr.end()){
                rr.erase(i);
                ws.insert(i);
            }
        }

        int upto = min(lneed - x1, x2 - rneed);
        while(upto){
            upto--;
            auto j = rr.begin();

            ll.insert(*j);
            ans.push_back({*j, {lft.back().second, rht.back().second}});
            rr.erase(j);
        }
        for(int i : ws) rr.insert(i);

        if(ll.size() == lneed) {finl.push_back(lft.back()); lft.pop_back();}
        if(rr.size() == rneed) {finr.push_back(rht.back()); rht.pop_back();}
    }


    while(!lft.empty()){

        set<int> ws;

        auto& ll = (lft.back()).first;
        auto& rr = (finr.back()).first;
        int x1 = ll.size();
        int x2 = rr.size();

        for(int i : ll){
            if(rr.find(i) != rr.end()){
                rr.erase(i);
                ws.insert(i);
            }
        }

        int upto = 1;
        while(upto){
            upto--;
            auto j = rr.begin();

            ll.insert(*j);
            ans.push_back({*j, {lft.back().second, finr.back().second}});
            rr.erase(j);
        }
        for(int i : ws) rr.insert(i);

        if(ll.size() == lneed) {lft.pop_back();}
        if(rr.size() < rneed) {finr.pop_back();}

    }


    while(!rht.empty()){

        set<int> ws;

        auto& ll = (finl.back()).first;
        auto& rr = (rht.back()).first;
        int x1 = ll.size();
        int x2 = rr.size();

        for(int i : ll){
            if(rr.find(i) != rr.end()){
                rr.erase(i);
                ws.insert(i);
            }
        }

        int upto = 1;
        while(upto){
            upto--;
            auto j = rr.begin();

            ll.insert(*j);
            ans.push_back({*j, {finl.back().second, rht.back().second}});
            rr.erase(j);
        }
        for(int i : ws) rr.insert(i);

        if(ll.size() > lneed) {finl.pop_back();}
        if(rr.size() == rneed) {rht.pop_back();}

    }

    cout << ans.size() << '\n';
    for(auto& x : ans){
        cout << x.second.second + 1 << ' ' << x.second.first + 1 << ' ' << x.first << '\n';
    }

    return 0;
}