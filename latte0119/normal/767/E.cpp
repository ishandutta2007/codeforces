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

int N,M;
int C[111111],W[111111];

int note[111111],coin[111111];

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N)scanf("%lld",&C[i]);
    rep(i,N)scanf("%lld",&W[i]);

    priority_queue<pint,vector<pint>,greater<pint>>que;
    int ans=0;
    rep(i,N){
        int c=C[i]%100;
        M-=c;
        if(c)que.push(pint((100-c)*W[i],i));
        note[i]=C[i]/100;
        coin[i]=c;
        if(M<0){
            M+=100;
            assert(que.size());
            int t=que.top().se;
            ans+=que.top().fi;
            que.pop();
            note[t]++;
            coin[t]=0;

        }
    }

    printf("%lld\n",ans);
    rep(i,N)printf("%lld %lld\n",note[i],coin[i]);
    return 0;
}