//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define F first
#define S second 

const int N = 2*1000*100 + 100; 

int cnt[N]; 

map<int,int> mp[N]; 

int main() { 
    ios::sync_with_stdio(false); cin.tie(0); 

    int n; 
    cin >> n; 

    ll ans = 0; 
    for(int i = 1; i <= n; i++) { 
        cin >> cnt[i]; 
        ans += cnt[i]; 
    }

    int q; 
    cin >> q; 

    for(int i = 0; i < q; i++) { 
        int s, t, u; 
        cin >> s >> t >> u; 

        if( mp[s][t] != 0 ) { 
            if(cnt[mp[s][t]] >= 0) 
                ans++; 
            cnt[mp[s][t]]++; 
        } 

        mp[s][t] = u; 
        if( mp[s][t] != 0 ) { 
            cnt[mp[s][t]]--; 
            if(cnt[mp[s][t]] >= 0) 
                ans--; 
        }

        cout << ans << '\n';
    }


}