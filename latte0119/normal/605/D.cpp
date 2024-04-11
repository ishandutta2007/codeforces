#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int SIZE=100000;
const int Z=500;

int N;
int A[SIZE],B[SIZE],C[SIZE],D[SIZE];

set<pint>ST[2*SIZE];
set<pint>SQ[2*SIZE/Z];

vint xs;

int prev[SIZE];

signed main(){
    scanf("%d",&N);
    rep(i,N){
        scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
        xs.pb(A[i]);
        xs.pb(C[i]);
    }

    sort(all(xs));
    xs.erase(unique(all(xs)),xs.end());

    queue<int>que;
    memset(prev,-1,sizeof(prev));

    rep(i,N){
        A[i]=lower_bound(all(xs),A[i])-xs.begin();
        C[i]=lower_bound(all(xs),C[i])-xs.begin();
        if(A[i]||B[i]){
            ST[A[i]].insert(pint(B[i],i));
            SQ[A[i]/Z].insert(pint(B[i],i));
        }
        else{
            prev[i]=i;
            que.push(i);
        }
    }


    while(que.size()){
        int v=que.front();que.pop();

        rep(i,C[v]/Z){
            while(SQ[i].size()&&SQ[i].begin()->first<=D[v]){
                int u=SQ[i].begin()->second;
                prev[u]=v;
                que.push(u);
                SQ[i].erase(pint(B[u],u));
                ST[A[u]].erase(pint(B[u],u));
            }
        }

        for(int i=C[v]/Z*Z;i<=C[v];i++){
            while(ST[i].size()&&ST[i].begin()->first<=D[v]){
                int u=ST[i].begin()->second;
                prev[u]=v;
                que.push(u);
                SQ[i/Z].erase(pint(B[u],u));
                ST[i].erase(pint(B[u],u));
            }
        }
    }
    if(prev[N-1]==-1){
        puts("-1");
        return 0;
    }

    vint ans;
    int v=N-1;
    while(true){
        ans.pb(v);
        if(prev[v]==v)break;
        v=prev[v];
    }

    reverse(all(ans));
    printf("%d\n",ans.size());
    rep(i,ans.size())printf("%d ",ans[i]+1);
    puts("");
    return 0;
}