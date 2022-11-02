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
int A[100000];
set<int>s;
vint vs;

int to[111111];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N)vs.pb(A[i]);
    vs.pb(0);
    sort(all(vs));
    rep(i,N)A[i]=lower_bound(all(vs),A[i])-vs.begin();
    s.insert(0);

    rep(i,N){
        auto it=s.lower_bound(A[i]);
        it--;
        int v=*it;
        int p;
        if(to[v]==v){
            p=v;
            to[v]=A[i];
        }
        else{
            p=to[v];
            to[v]=A[i];
        }
        to[A[i]]=A[i];
        s.insert(A[i]);
        if(i)printf("%lld ",vs[p]);
    }
    puts("");
    return 0;
}