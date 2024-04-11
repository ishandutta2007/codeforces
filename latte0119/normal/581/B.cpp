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

int N;
int A[111111];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);

    int ma=0;
    vint ans;
    for(int i=N-1;i>=0;i--){
        ans.pb(max(ma+1-A[i],0ll));
        chmax(ma,A[i]);
    }
    reverse(all(ans));
    rep(i,N)cout<<ans[i]<<" ";cout<<endl;
    return 0;
}