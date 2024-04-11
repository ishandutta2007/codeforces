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
        int n,m;cin >> n >> m;
        string str[n+1];
        for(int i=1;i<n+1;i++){
            string s;cin >> s;
            str[i] = s;
        }
        int hor[n+1]; int ver[m+1];
        memset(hor, 0, sizeof(hor));memset(ver, 0, sizeof(ver));
        for(int i=1;i<n+1;i++){
            string s = str[i];
            for(int j=0;j<s.size();j++){
                if(s[j] == '.'){
                    hor[i]++;
                }
            }
            // cout << hor[i] << " ";
        }
        // cout << endl;
        for(int j=0;j<m;j++){
            for(int i=1;i<=n;i++){
                if(str[i][j] == '.'){
                    ver[j+1]++;
                }
            }
            // cout << ver[j+1] << " ";
        }
        // cout << endl;
        int ans = mod;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ma = 0;
                if(str[i][j-1] == '.'){
                    ma = hor[i] + ver[j] - 1;
                }
                else{
                    ma = hor[i] + ver[j];
                }
                ans = min(ma, ans);
            }
        }
        cout << ans << endl;
    }
}