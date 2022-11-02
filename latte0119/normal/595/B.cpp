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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int mod=1000000007;

int N,K;
int a[100000],b[100000];

signed main(){
    cin.tie();ios_base::sync_with_stdio(0);

    cin>>N>>K;
    rep(i,N/K)cin>>a[i];
    rep(i,N/K)cin>>b[i];

    int x=1;
    rep(i,K)x*=10;

    int ans=1;
    rep(i,N/K){
        int foo=(x-1)/a[i]+1;
        int u=(x/10*(b[i]+1)-1)/a[i]+1;
        int l=b[i]?((x/10*b[i]-1)/a[i]+1):0;
        foo-=u-l;
        ans=ans*foo%mod;
    }
    cout<<ans<<endl;

    return 0;
}