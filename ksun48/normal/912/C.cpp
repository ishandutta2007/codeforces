#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL n, m;
    cin >> n >> m;
    LL bounty, increase, damage;
    cin >> bounty >> increase >> damage;
    LL regen[n];
    LL maxh[n]; 
    vector<pair<LL,LL> > f[n];
    for(int i = 0; i < n; i++){
        cin >> maxh[i];
        LL s;
        cin >> s;
        cin >> regen[i];
        if(increase > 0){
            if(damage >= maxh[i]){
                cout << -1 << endl;
                return 0;
            }
        }
        f[i].push_back({0, s});
        f[i].push_back({3000000000LL, maxh[i]});
    }
    for(int i = 0; i < m; i++){
        LL t, enemy, health;
        cin >> t >> enemy >> health;
        enemy--;
        f[enemy].push_back({t, health});
    }
    vector<pair<LL,LL> > ev;
    for(int j = 0; j < n; j++){
        sort(f[j].begin(), f[j].end());
        if(increase > 0 && regen[j] == 0 && f[j][f[j].size()-2].second <= damage){
            cout << -1 << endl;
            return 0;
        }
        for(int r = 0; r + 1 < f[j].size(); r++){
            LL starttime = f[j][r].first;
            LL endtime = f[j][r+1].first-1;
            LL starthealth = f[j][r].second;
            if(damage < starthealth) continue;
            ev.push_back({-starttime+1, -1});
            //diff[-(starttime-1)]--;
            if(regen[j] != 0){
                LL secs = (damage - starthealth) / regen[j];
                endtime = min(endtime, starttime + secs);
            }
            ev.push_back({-endtime, 1});
            //diff[-endtime]++;
        }
    }
    sort(ev.begin(), ev.end());
    LL cur = 0;
    LL best = 0;
    int z = 0;
    LL t = 0;
    while(z < ev.size()){
        cur += ev[z].second;
        t = ev[z].first;
        z++;
        while(z < ev.size() && ev[z].first == t){
            cur += ev[z].second;
            z++;
        }
        best = max(best, cur*(bounty-t*increase) );
    }
    cout << best << endl;
}