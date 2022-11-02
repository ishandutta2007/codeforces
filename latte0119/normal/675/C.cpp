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

int N;
int A[333333];
int S[333333];
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld",&A[i]);
        A[i+N]=A[i];
    }

    rep(i,2*N)S[i+1]=S[i]+A[i];

    map<int,int>cnt;
    int mi=N;
    for(int i=1;i<=2*N;i++){
        cnt[S[i]]++;
        if(i<N)continue;
        int tmp=cnt[S[i-N]];
        chmin(mi,N-tmp);
        cnt[S[i-N+1]]--;
    }
    printf("%lld\n",mi);
    return 0;
}