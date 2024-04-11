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

signed main(){
    int N,M;
    cin>>N>>M;
    vint A(N);rep(i,N)cin>>A[i];
    A.pb(0);A.pb(1000000001);
    sort(all(A));
    vint ans;
    int sum=0;
    rep(i,A.size()-1){
        for(int j=A[i]+1;j<A[i+1];j++){
            sum+=j;if(sum>M)break;
            ans.pb(j);
        }
        if(sum>M)break;
    }
    printf("%lld\n",(int)ans.size());
    rep(i,ans.size())printf("%lld ",ans[i]);
    return 0;
}