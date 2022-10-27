#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
pair<int, int> p[nax];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    for(cin >> T ; T -- ; ){
        cin >> n;
        for(int i = 1;i <= n; i ++)
            cin >> p[i].first >> p[i].second;
        sort(p + 1  ,  p + 1 + n);
        auto last = make_pair(0, 0);
        auto solve = [&]() -> pair<string, bool>{
            string res;
            for(int i = 1 ;i <= n; i ++){
                auto now = p[i];
                if(last.first > now.first || last.second > now.second){
                    return make_pair("a", false);
                }
                for(int j = last.first  ;j < now.first ;j ++)
                    res += 'R';
                for(int j = last.second ; j < now.second ;j ++)
                    res += 'U';
                last = now;
            }
            return make_pair(res, true);
        };
        auto m = solve();
        if(m.second){
            cout << "YES\n" << m.first << '\n';
        }
        else cout << "NO\n";
    }
}
/*
    Good Luck
        -Lucina
*/