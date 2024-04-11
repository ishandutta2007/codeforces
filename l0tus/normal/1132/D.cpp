#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<ll,ll> pii;
using namespace std;
const int MN = 2e5+5;
const int INF = 1e9;

ll A[MN],B[MN],N,M,K,cnt,tmp,ans,val,D[MN];
string S;

bool check(ll x)
{
    ll res = 0;
    for(int i=0; i<K; i++) D[i]=0;
    for(int i=0; i<N; i++){
        if(A[i]>=K*B[i]) continue;
        res += (K*B[i]-A[i]-1)/x+1;
    }
    if(res>K) return false;

    for(int i=0; i<N; i++){
        if(A[i]>=K*B[i]) continue;
        ll cnt = A[i], val = 0;
        while(1){
            val += cnt/B[i];
            if(val>=K) break;
            D[val]++;
            cnt = (cnt%B[i])+x;
        }
    }
    res = 0;
    for(int i=0; i<K; i++){
        res += D[i];
        if(res>i+1) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> K;
    K--;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<N; i++){
        cin >> B[i];
    }
    bool ispos = true;
    for(int i=0; i<N; i++){
        if(A[i]<K*B[i]) ispos = false;
    }
    if(ispos){
        cout << 0;
        return 0;
    }
    ll s=1,e=1e13,m;
    while(s<e){
        m = (s+e)/2;
        if(check(m)) e = m;
        else s = m+1;
    }
    if(s==1e13) cout << -1;
    else cout << s;
}