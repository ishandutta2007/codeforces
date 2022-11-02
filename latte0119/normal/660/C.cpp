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
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,f,n) for(int i=(int)(f);i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N,M;
int A[333333];

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N)scanf("%lld",&A[i]);

    int r=0;
    int ma=-1,val=-1,cnt=0;
    rep(i,N){
        if(r<i){
            r=i;
            cnt=0;
        }
        while(r<N&&(cnt<M||A[r]))cnt+=A[r++]==0;
        if(r-i>val){
            val=r-i;
            ma=i;
        }
        if(!A[i])cnt--;
    }

    reps(i,ma,N){
        if(M){
            M-=A[i]==0;
            A[i]=1;
        }
    }

    printf("%lld\n",val);
    rep(i,N)printf("%lld ",A[i]);
    puts("");
}