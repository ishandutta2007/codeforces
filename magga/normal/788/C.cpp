#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
long long modinv(long long a, long long mod) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a/b;
        a -= t*b; swap(a, b);
        u -= t*v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}
namespace NTT {
    const long long int MOD = 998244353;
    const long long PR = 3; 
    void trans(vector<long long> &v, bool inv = false) {
        long long int n = (long long int)v.size();
        for (long long int i = 0, j = 1; j < n-1; j++) {
            for (long long int k = n>>1; k > (i ^= k); k >>= 1);
            if (i > j) swap(v[i], v[j]);
        }
        for (long long int t = 2; t <= n; t <<= 1) {
            long long bw = modpow(PR, (MOD-1)/t, MOD);
            if (inv) bw = modinv(bw, MOD);
            for (int i = 0; i < n; i += t) {
                long long w = 1;
                for (int j = 0; j < t/2; ++j) {
                    int j1 = i + j, j2 = i + j + t/2;
                    long long c1 = v[j1], c2 = v[j2] * w % MOD;
                    v[j1] = c1 + c2;
                    v[j2] = c1 - c2 + MOD;
                    while (v[j1] >= MOD) v[j1] -= MOD;
                    while (v[j2] >= MOD) v[j2] -= MOD;
                    w = w * bw % MOD;
                }
            }
        }
        if (inv) {
            long long inv_n = modinv(n, MOD);
            for (int i = 0; i < n; ++i) v[i] = v[i] * inv_n % MOD;
        }
    }
    vector<long long> mult(vector<long long>&A, vector<long long> &B) {
        int size_a = 1; while (size_a < A.size()) size_a <<= 1;
        int size_b = 1; while (size_b < B.size()) size_b <<= 1;
        int size_fft = max(size_a, size_b) << 1;
        vector<long long> cA(size_fft, 0), cB(size_fft, 0), cC(size_fft, 0);
        for (int i = 0; i < A.size(); ++i) cA[i] = A[i];
        for (int i = 0; i < B.size(); ++i) cB[i] = B[i];
        trans(cA); trans(cB);
        for (int i = 0; i < size_fft; ++i) cC[i] = cA[i] * cB[i] % MOD;
        trans(cC, true);
        vector<long long> res((int)A.size() + (int)B.size() - 1);
        for (int i = 0; i < res.size(); ++i) res[i] = cC[i];
        return res;
    }
};
void pre(){}
void solve(){
    ll n,k,d;cin>>n>>k;
    vector<ll>arr(1001,0);
    ll mi = 1000,ma = 0;
    for(int i=0;i<k;i++){
        cin>>d;
        mi = min(mi,d);
        ma = max(ma,d);
        arr[d]=1;
    }
    if(n<mi || n>ma){
        cout<<-1<<"\n";
        return;
    }
    vector<ll>curr(1000+1,0),temp;
    curr = arr;
    if(arr[n]){
        cout<<1<<"\n";
        return;
    }
    for(int i=1;i<=2000;i++){
        temp = NTT::mult(curr,arr);
        for(int i = n;i<=n+1000;i++){
            if(temp[i]>0){
                curr[i-n]=1;
            }else{
                curr[i-n]=0;
            }
        }
        if(curr[n]){
            cout<<i+1<<"\n";
            return;
        }
    }
    cout<<-1<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}