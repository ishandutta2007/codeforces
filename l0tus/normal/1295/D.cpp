#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll T,A,M,D,X;
vector<ll> P;
bool ch[100000],dp[21];
ll GCD(ll A, ll B)
{
    if(A<B) swap(A,B);
    if(B==0) return A;
    return GCD(B,A%B);
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    for(int i=2; i<100000; i++){
        if(ch[i]) continue;
        P.push_back(i);
        for(int j=2; i*j<100000; j++) ch[i*j]=1;
    }
    cin >> T;
    while(T--){
        cin >> A >> M;
        D = GCD(A,M);
        X = M/D;
        vector<ll> div;
        for(ll p : P){
            if(X%p) continue;
            div.push_back(p);
            while(X%p==0) X/=p;
        }
        if(X!=1) div.push_back(X);
        int sz = div.size();
        ll ans = (A+M)/D-A/D;
        for(int i=1; i<(1<<sz); i++){
            ll num = 1, cnt = 0;
            for(int j=0; j<sz; j++){
                if(i&(1<<j)){
                    num*=div[j];
                    cnt++;
                }
            }
            if(cnt%2) ans -= ((A+M)/D-1)/num-(A/D-1)/num;
            else ans += ((A+M)/D-1)/num-(A/D-1)/num;
        }
        cout << ans << '\n';
    }
}