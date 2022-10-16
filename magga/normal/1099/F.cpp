#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
long long int n = 1<<20,ni,T;
vector<int>arr[100001];
ll cookies[100001];
ll cost[100001];
ll travel[100001]{0};
ll ans = 1e18;
ll  u,v,w;
const long long int N = (1<<20)+1;
pii t[2*N];
pii combine(pii &a,pii &b){
    return {a.F+b.F,a.S+b.S};
}
void build(){
    for(long long int i=n-1;i>0;i--){
        t[i]=combine(t[i<<1],t[i<<1|1]);
    }
}
void modify(long long int p,long long int value){
    p+=n;
    t[p].F+=value;
    t[p].S+=value*(p-n);
    for(;p>1;p>>=1){
        t[p>>1]=combine(t[p],t[p^1]);
    } 
}
long long int query(){
    if(T>=t[1].S){
        return t[1].F;
    }
    long long int ret = 0;
    long long int ans = 0;
    long long int curr = 1;
    while(curr<n){
        curr*=2;
        if(ret+t[curr].S>T){
            continue;
        }else{
            ret+=t[curr].S;
            ans+=t[curr].F;
            curr|=1;
        }
    }
    if(curr!=n)
        ans+=(T-ret)/(curr-n);
    return ans;
}
long long int dfs(int to,int from){
    modify(cost[to],cookies[to]);
    T-=travel[to];
    long long int ret = query();
    priority_queue<long long int>pq;
    for(auto i:arr[to]){
        if(i!=from){
            pq.push(dfs(i,to));
        }
    }
    T+=travel[to];
    modify(cost[to],-1*cookies[to]);
    if(to==1){
        if(pq.size()>0){
            ret = max(ret,pq.top());
        }
        return ret;
    }
    if(pq.size()<2){
        return ret;
    }else{
        pq.pop();
        return max(ret,pq.top());
    }
}
void pre(){}
void solve(){
    cin>>ni>>T;
    for(int i=1;i<=ni;i++) cin>>cookies[i];
    for(int i=1;i<=ni;i++) cin>>cost[i];
    for(int i=2;i<=ni;i++){
        cin>>u>>v;
        arr[u].pb(i);
        arr[i].pb(u);
        travel[i]=2*v;
    }
    cout<<dfs(1,0)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}