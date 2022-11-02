#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N,K;
int A,B,C,D;
bool used[1000+1];
signed main(){
    cin>>N>>K;
    cin>>A>>B>>C>>D;
    used[A]=used[B]=used[C]=used[D]=true;

    if(N==4||K<=N){
        puts("-1");
        return 0;
    }

    printf("%lld %lld ",A,C);
    reps(i,1,N+1)if(!used[i])printf("%lld ",i);
    printf("%lld %lld\n",D,B);

    printf("%lld %lld ",C,A);
    reps(i,1,N+1)if(!used[i])printf("%lld ",i);
    printf("%lld %lld\n",B,D);
    return 0;
}