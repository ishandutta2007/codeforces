#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n;
        cin >> n;
        map<pair<int,int>,long long> mp;
        rep(i,n){
            int x,y;
            int a,b;
            cin >> x >> y >> a >> b;
            int p = a-x;
            int q = b-y;
            int g = gcd(abs(p),abs(q));
            p/= g;
            q/= g;
            mp[make_pair(p,q)]++;
        }
        long long res = 0;
        for(auto x:mp){
            if(mp.find(make_pair(-x.first.first,-x.first.second))!=mp.end()){
                res += x.second * mp[make_pair(-x.first.first,-x.first.second)];
            }
        }
        cout << res/2 << "\n";
    }

    return 0;
}