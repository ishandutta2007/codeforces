#include<bits/stdc++.h>
using namespace std;
 
#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
 
const int M=31622777;
bool f[M];
 
vpint p;
vint v;
 
void dfs(int n,int m){
    if(n==p.size()){
        v.pb(m);
        return;
    }
    for(int i=0;i<=p[n].se;i++){
        dfs(n+1,m);
        m*=p[n].fi;
    }
}
signed main(){
    int N,K;cin>>N>>K;K--;
 
    fill_n(f,M,1);f[0]=f[1]=0;
    for(int i=2;i<M;i++){
        if(!f[i])continue;
        if(N%i==0){
            int cnt=0;
            while(N%i==0){
                N/=i;cnt++;
            }
            p.pb({i,cnt});
        }
        for(int j=i+i;j<M;j+=i)f[j]=0;
    }
	if(N!=1)p.emplace_back(N,1);
    dfs(0,1);
    sort(all(v));
    if(v.size()>K)cout<<v[K]<<endl;
    else cout<<-1<<endl;
    return 0;
}