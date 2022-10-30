#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,M;
vint A[50];
int B[250000];

int lef[50],rig[50],val[50],al[50];

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>N>>M;
    rep(i,N){
        int n;cin>>n;
        A[i].resize(n);
        rep(j,n)cin>>A[i][j];
    }

    rep(i,M)cin>>B[i],B[i]--;

    rep(i,N){
        lef[i]=LLONG_MIN;
        int sum=0;
        for(int j=0;j<A[i].size();j++){
            sum+=A[i][j];
            chmax(lef[i],sum);
        }

        rig[i]=LLONG_MIN;
        sum=0;
        for(int j=A[i].size()-1;j>=0;j--){
            sum+=A[i][j];
            chmax(rig[i],sum);
        }

        val[i]=LLONG_MIN;
        int mi=0;
        sum=0;
        rep(j,A[i].size()){
            sum+=A[i][j];
            chmax(val[i],sum-mi);
            chmin(mi,sum);
        }
        al[i]=sum;
    }

    int ma=0;
    int sum=0;
    int ans=LLONG_MIN;
    rep(i,M){
        chmax(ans,lef[B[i]]+sum+ma);
        sum+=al[B[i]];
        chmax(ma,-sum+max(0ll,rig[B[i]]));
    }
    rep(i,M)chmax(ans,val[B[i]]);
    cout<<ans<<endl;
    return 0;
}