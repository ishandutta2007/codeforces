#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

const int mod=1000000007;

int N;
int H[1000000];
int f[1000000],g[1000000];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&H[i]),H[i]--;

    int ans=0;
    rep(i,N){
        if(i){
            if(H[i-1]>=H[i]){
                if(i+1==N||H[i+1]>=H[i]){
                    f[i]=0;
                    g[i]=g[i-1]*H[i]%mod;
                }
                else{
                    f[i]=(H[i]-H[i+1])*g[i-1]%mod;
                    g[i]=H[i+1]*g[i-1]%mod;
                }
            }
            else{
                if(i+1==N||H[i+1]>=H[i]){
                    f[i]=0;
                    g[i]=g[i-1]*H[i-1]%mod;
                }
                else if(H[i-1]<=H[i+1]){
                    f[i]=0;
                    g[i]=g[i-1]*H[i-1]%mod;
                }
                else{
                    f[i]=(H[i-1]-H[i+1])*g[i-1]%mod;
                    g[i]=H[i+1]*g[i-1]%mod;
                }
            }
        }
        if(i+1==N||H[i+1]>=H[i]){
            g[i]=(g[i]+H[i])%mod;
        }
        else{
            f[i]=(f[i]+(H[i]-H[i+1]))%mod;
            g[i]=(g[i]+H[i+1])%mod;
        }
        ans=(ans+f[i]+g[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}