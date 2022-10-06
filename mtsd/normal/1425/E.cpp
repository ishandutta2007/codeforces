#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
ll dp[200000];
ll sm[200000];
ll dp2[200000];
ll sm2[200000];
ll mi[200000];
int main(){
    int n,k;
    cin >> n >> k;
    vector<ll> a(n),d(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> d[i];
    if(k==0){
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                sm2[i] = a[i];
                dp2[i] = max(0LL,a[i]-d[i]);
            }else{
                sm2[i] = sm2[i+1] + a[i];
                dp2[i] = max(dp2[i+1], sm2[i]-d[i]);
            }
        }
        cout << dp2[0] << endl;
    }else if(k==1){
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                sm2[i] = a[i];
                dp2[i] = max(0LL,a[i]-d[i]);
            }else{
                sm2[i] = sm2[i+1] + a[i];
                dp2[i] = max(dp2[i+1], sm2[i]-d[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(i==0){
                mi[i] = d[i];
                sm[i] = a[i];
                dp[i] = a[i]-d[i];
            }else{
                mi[i] = min(mi[i-1],d[i]);
                sm[i] = sm[i-1] + a[i];
                dp[i] = max(dp[i-1] + a[i], a[i]-d[i]);
            }
        }
        ll mx = 0;
        rep(i,n-1){
            if(i==0){
                mx = max(mx,sm2[2] + a[0]-d[0]);
                mx = max(mx,sm2[2] + a[1]-d[1]);
                mx = max(mx,sm2[2] + a[0]-d[0] + a[1]-d[1]);
                mx = max(mx,dp2[2]);
            }else{
                ll tmp = 0;
                ll tmp2  = 0;
                if(i!=n-2){
                    tmp = max(tmp,sm2[i+2] + dp[i]);
                    tmp = max(tmp,sm2[i+2] + a[i+1]-d[i+1]);
                    tmp = max(tmp,sm2[i+2] + dp[i] + a[i+1]-d[i+1]);
                    tmp = max(tmp,dp2[i+2]);
                    mx = max(mx,tmp);
                }
                tmp = 0;
                tmp = max(0LL,sm[i]-mi[i]);
                mx = max(mx,tmp + dp2[i+1]);
            }
            // cerr << i << " " << mx << endl;
        }

        cout << mx << endl;
    }else{
        ll s = 0;
        ll mi = (1LL<<60);
        rep(i,n){
            s += a[i];
            if(i!=n-1)mi = min(mi,d[i]);
        }
        cout << max(max(s-mi,0LL),a[n-1]-d[n-1]) << endl;
    }
    return 0;
}