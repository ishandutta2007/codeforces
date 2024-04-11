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

int N,K;
int A[111111];
signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld",&A[i+1]),A[i+1]+=A[i];

    map<int,int>cnt;
    cnt[0]++;
    int ans=0;
    for(int i=1;i<=N;i++){
        int t=1;
        while(true){
            int to=A[i]-t;
            if(cnt.find(to)!=cnt.end())ans+=cnt[to];
            t*=K;
            if(K==1)break;
            if(K==-1&&t==1)break;
            if(abs(t)>(1e15))break;
        }
        cnt[A[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}