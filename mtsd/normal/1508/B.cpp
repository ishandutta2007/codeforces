#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
ll dp[100010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false); 
    int t;
    cin >> t;
    dp[0] = 1;
    dp[1] = 1;
    ll INF = (1LL<<60);
    for(int i=2;i<=100000;i++){
        dp[i] = 2LL*dp[i-1];
        if(dp[i]>=INF)dp[i] = INF;
    }
    rep(zz,t){
        ll n,k;
        cin >> n >> k;
        vector<int> res;
        if(dp[n]< k){
            cout << -1 << "\n";
            continue;
        }
        int id = n;
        while(id>0){
            if(dp[id-1] >= k){
                res.push_back(n-id+1);
                id--;
            }else{
                int len = 0;
                rep(i,100){
                    if(dp[id-i-1]<k){
                        k -= dp[id-i-1];
                    }else{
                        len = i+1;
                        break;
                    }
                }
                rep(i,len){
                    res.push_back(n-id+len-i);
                }
                id -= len;
            }
        }
        rep(i,n){
            cout << res[i];
            if(i!=n-1)cout << " ";
        }
        cout << "\n";
    }
    return 0;
}