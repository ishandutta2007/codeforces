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
int A[100000];

signed main(){
    scanf("%lld%lld",&N,&K);

    priority_queue<pint,vector<pint>,greater<pint> >que;
    rep(i,N){
        scanf("%lld",&A[i]);
        if(A[i]!=100)que.push(pint((A[i]/10+1)*10-A[i],i));
    }

    while(que.size()){
        pint p=que.top();que.pop();
        if(p.fi>K)break;
        A[p.se]+=p.fi;
        K-=p.fi;
        if(A[p.se]==100)continue;
        que.push(pint(10,p.se));
    }

    int ans=0;
    rep(i,N)ans+=A[i]/10;
    printf("%lld\n",ans);
    return 0;
}