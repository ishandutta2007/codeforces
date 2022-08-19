#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    LL n, T;
    cin >> n >> T;
    vector<pair<LL,pair<LL,LL> > > times;

    for(int i = 0; i < n; i++){
        LL a, t;
        cin >> a >> t;
        times.push_back({t,{a, i+1} });
    }
    sort(times.begin(), times.end());

    LL s = 0;
    LL e = n+1;
    while(s+1 < e){
        LL m = (s+e)/2;
        vector<LL> a;
        for(int c = 0; c < n; c++){
            if(times[c].second.first < m) continue;
            a.push_back(times[c].first);
        }
        int ok = 0;
        LL curT = T;
        if(a.size() < m){
            e = m;
        } else {
            for(int c = 0; c < m; c++){
                curT -= a[c];
            }
            if(curT >= 0){
                s = m;
            } else {
                e = m;
            }
        }
    }
    cout << s << '\n';
    cout << s << '\n';
    vector<LL> a;
    for(int c = 0; c < n; c++){
        if(times[c].second.first < s) continue;
        a.push_back(c);
    }
    for(int i = 0; i < s; i++){
        cout << times[a[i]].second.second << " ";
    }
    cout << '\n';
}