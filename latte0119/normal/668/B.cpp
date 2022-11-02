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

int N,Q;
int T[2000000],A[2000000];
int ans[1000000];
signed main(){
    scanf("%lld%lld",&N,&Q);
    rep(i,Q){
        scanf("%lld",&T[i]);
        if(T[i]==1)scanf("%lld",&A[i]);
    }

    rep(t,2){
        int c=t;
        int a=0;
        rep(i,Q){
            if(T[i]==1){
                if(A[i]%2==0)a+=A[i];
                else{
                    if(c){
                        a+=A[i]+1;
                    }
                    else{
                        a+=A[i]-1;
                    }
                    c^=1;
                }
            }
            else{
                c^=1;
            }
        }
        for(int i=t;i<N;i+=2){
            int tmp=(i-t+a+c+N*1000000000ll)%N;
            ans[tmp]=i;
        }
    }

    rep(i,N)printf("%lld ",ans[i]+1);
    return 0;
}