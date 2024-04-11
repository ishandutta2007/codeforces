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

int K,N;
int A[111111];

vint lis[111111];

signed main(){
    cin.tie(0);ios_base::sync_with_stdio(0);

    cin>>K>>N;
    rep(i,N)cin>>A[i],A[i]--;

    rep(i,N){
        if(i&&A[i-1]!=A[i])lis[A[i]].pb(A[i-1]);
        if(i+1!=N&&A[i+1]!=A[i])lis[A[i]].pb(A[i+1]);
    }


    int b=0;
    rep(i,N-1)b+=abs(A[i+1]-A[i]);


    int mi=0;
    rep(i,K){
        sort(all(lis[i]));
        if(lis[i].size()==0)continue;
        int val=0;
        for(auto u:lis[i])val-=abs(u-i);

        int tmp=lis[i][lis[i].size()/2];
        for(auto u:lis[i])val+=abs(u-tmp);
        chmin(mi,val);
    }

    cout<<b+mi<<endl;
    return 0;
}