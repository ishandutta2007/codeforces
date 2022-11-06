#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define MOD 998244353
#define INF (ll)1e+18
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;

ll kai[N];
ll rk[N];

void init(void){
    kai[0]=1;
    rep(i,N-1)kai[i+1]=(kai[i]*(i+1))%MOD;
    bool b[30];
    ll x=MOD-2;
    rep(i,30){
        if(x%2==1)b[i]=true;
        else b[i]=false;
        x/=2;
    }
    rep(i,N){
        rk[i]=1;
        x=kai[i];
        rep(j,30){
            if(b[j])rk[i]=(rk[i]*x)%MOD;
            x=(x*x)%MOD;
        }
    }
    return;
}

ll nik(int a,int b){
    ll re=(rk[a-b]*rk[b])%MOD;
    return (kai[a]*re)%MOD;
}

int main() {
    int t,n,k,r;
    ll x,y,s;
    ll a[N];
    ll sa[N];
    ll ta[N];
    int b[N];
    init();

    cin >> t;
    rep(tt,t){
        cin >> n;
        k=0;
        s=0;
        b[0]=0;
        rep(i,n){
            cin >> x;
            s += x;
            if(x==0)b[k]++;
            else{
                a[k]=x;
                k++;
                b[k]=0;
            }
        }
        if(k==0){
            x=1;
            rep(i,n-1)x=(x*2)%MOD;
            cout << x <<endl;
            continue;
        }


        sa[0]=a[0];
        rep(i,k-1)sa[i+1]=sa[i]+a[i+1];
        ta[k-1]=a[k-1];
        rep3(i,k-2,0)ta[i]=ta[i+1]+a[i];
        r=k-1;
        x=1;
        y=0;
        rep(i,min(b[0],b[k])+1){
            y+=nik(b[0],i)*nik(b[k],i);
            y%=MOD;
        }
        x=(x*y)%MOD;
        rep(i,k){
            if((sa[i]*2)>s)break;
            while(sa[i]>ta[r])r--;
            if(sa[i]*2==s){
                rep(j,b[i+1]+1)x=(x*2)%MOD;
                break;
            }
            if(sa[i]==ta[r]){
                y=0;
                rep(j,min(b[i+1]+1,b[r]+1)+1){
                    y+=nik(b[i+1]+1,j)*nik(b[r]+1,j);
                    y%=MOD;
                }
                x=(x*y)%MOD;
            }
        }
        cout << x << endl;
    }
	return 0;
}