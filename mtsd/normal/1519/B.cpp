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
bool dp[102][102][10001];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    dp[1][1][0] = 1;
    rep(i,101){
        rep(j,i+1){
            rep(k,10000){
                if(!dp[i][j][k])continue;
                if(k+i<=10000){
                    dp[i][j+1][k+i] = 1;
                }
                if(k+j<=10000){
                    dp[i+1][j][k+j] = 1;
                }
            }
        }
    }
    rep(zz,t){
        ll n,m,k;
        cin >> n >> m >> k;
        if(n<m)swap(n,m);
        if(dp[n][m][k]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}