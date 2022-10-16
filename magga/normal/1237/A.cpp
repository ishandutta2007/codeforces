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
    vector<int>vec;
    int even = 0;
    int odd_val = 0;int even_val = 0;
    vector<int>orig;
    vector<int>odd_index;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        if(a%2 == 0){
            even++;
            even_val += a/2;
        }
        else{
            odd_val += a/2;
            odd_index.push_back(i);
        }
        orig.push_back(a);
        vec.push_back(a/2);
    }
    ll diff = odd_val + even_val;
    for(int i=0;i<odd_index.size();i++){
        if((diff > 0 && vec[odd_index[i]] < 0) || (diff > 0 && vec[odd_index[i]] == 0 && orig[odd_index[i]] < 0)){
            vec[odd_index[i]]--;
            diff--;
        }
        else if((diff < 0 && vec[odd_index[i]] > 0) || (diff < 0 && vec[odd_index[i]] == 0 && orig[odd_index[i]] > 0)){
            vec[odd_index[i]]++;
            diff++;
        }
        if(diff == 0){
            break;
        }
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << "\n";
    }
    return 0;
}