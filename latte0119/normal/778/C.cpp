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

const int POOL_SIZE=1000000;
struct node{
    int cnt;
    node *to[26];
    node(){rep(i,26)to[i]=NULL;}
}pool[POOL_SIZE];
int cur;
node *alloc(){
    pool[cur].cnt=0;
    rep(i,26)pool[cur].to[i]=NULL;
    return &pool[cur++];
}

int N;
vector<pint>G[333333];
node t[333333];
node *build(int v){
    t[v].cnt=1;
    for(auto &e:G[v]){
        t[v].to[e.se]=build(e.fi);
        t[v].cnt+=t[v].to[e.se]->cnt;
    }
    return &t[v];
}

int ans[333333];

node *merge(node *a,node *b){
    if(a==NULL)return b;
    if(b==NULL)return a;
    node *s=alloc();
    s->cnt=1;
    for(int i=0;i<26;i++){
        s->to[i]=merge(a->to[i],b->to[i]);
        if(s->to[i])s->cnt+=s->to[i]->cnt;
    }
    return s;
}

void dfs(int v,int d){
    if(G[v].size()==0)return;

    for(auto &e:G[v]){
        dfs(e.fi,d+1);
    }

    cur=0;
    node *s=NULL;
    for(auto &e:G[v]){
        s=merge(s,&t[e.fi]);
    }
    ans[d+1]+=t[v].cnt-1-s->cnt+1;
}

signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        int a,b;
        char c;
        scanf("%lld%lld %c",&a,&b,&c);
        a--;b--;
        G[a].pb({b,c-'a'});
    }

    build(0);
    dfs(0,0);

    int tmp=max_element(ans,ans+N)-ans;
    cout<<N-ans[tmp]<<endl;
    cout<<tmp<<endl;
    return 0;
}