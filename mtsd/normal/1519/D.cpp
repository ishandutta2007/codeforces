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
#define int long long
int dp[5001][5001];
int p[5001];
int q[5001];
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    for(int d=0;d<=n-1;d++){
        for(int L=0;L<n-d;L++){
            int R = L+d;
            if(L==R){
                dp[L][R] = a[L]*b[L];
            }else if(d==1){
                dp[L][R] = a[L]*b[R] + a[R]*b[L];
            }else{
                dp[L][R] = dp[L+1][R-1] + a[L]*b[R] + a[R]*b[L];
            }
        }
    }
    rep(i,n){
        p[i+1] += a[i]*b[i];
        p[i+1] += p[i];
    }
    for(int i=n-1;i>=0;i--){
        q[i] += a[i]*b[i];
        q[i] += q[i+1]; 
    }
    ll mx = p[n-1];
    rep(L,n){
        for(int R=L;R<n;R++){
            chmax(mx, dp[L][R] + p[L] + q[R+1] );
        }
    }
    cout << mx << endl;
    return 0;
}