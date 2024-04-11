#include<bits/stdc++.h>
using namespace std;
 
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, vector<int>> pivi;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<int , vi> mivi;
#define MAX_N 100005
ll mod = 1e9+7;
ll maxn = 1e13;

int main(){
    io;
    int n;cin >> n;
    map<ll, map<ll, map<ll, ll>>> m; 
    for(int i=0;i<n;i++){
        ll a,b,c; cin >> a >> b >> c;
        m[a][b][c] = i+1;
    }
    vector<ll>rem;
    for(auto x : m){
        // cout << top.first << " this is value " << top.second.size() << endl;
        map<ll, map<ll, ll>> m1 = x.second;
        ll res = -1;
        for(auto y : m1){
            map<ll, ll> m2 = y.second;
            ll res1 = -1;
            for(auto z : m2){
                if(res1 != -1){
                    cout << res1 << " " << z.second << "\n";
                    res1 = -1;
                }
                else{
                    res1 = z.second;
                }
            }
            if(res1 != -1){
                if(res != -1){
                    cout << res << " " << res1 << endl;
                    res = -1; res1 = -1;
                }
                else{
                    res = res1; res1 = -1;
                }
            }
        }
        if(res != -1){
            rem.push_back(res);
        }
    }
    for(int i=0;i<(rem.size()/2);i++){
        cout << rem[2*i] << " " << rem[2*i+1] << "\n";
    }
    return 0;
}