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
    int t;cin >> t;
    while(t--){
        ll n,k;cin >> n >> k;
        bool ans = false;
        if(k%3 == 0){
            ll n1 = n%(k+1);
            if(n1%3 == 0 && n1 != k){
                ans = true;
            }
        }
        else{
            ll n1 = n%3;
            if(n1 == 0){
                ans = true;
            }
        }
        ans ? cout << "Bob" << "\n" : cout << "Alice" << "\n";
    }
}