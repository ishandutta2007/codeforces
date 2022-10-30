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

string S;

vector<string>pool[1000000];

void dfs(int &cur,int d){
    int nex=cur;
    while(S[nex]!=',')nex++;
    string t=S.substr(cur,nex-cur);
    pool[d].pb(t);
    nex++;
    int c=0;
    while(S[nex]!=','){
        c=c*10+S[nex]-'0';
        nex++;
    }
    nex++;
    cur=nex;
    rep(i,c)dfs(cur,d+1);
}

signed main(){
    cin.tie(0);ios_base::sync_with_stdio(0);

    cin>>S;S+=",";
    int cur=0;
    while(cur<S.size())dfs(cur,0);
    int d=0;
    rep(i,1000000)if(pool[i].size())d=i;
    cout<<d+1<<"\n";
    rep(i,d+1){
        rep(j,pool[i].size()){
            if(j)cout<<" ";
            cout<<pool[i][j];
        }
        cout<<"\n";
    }
    return 0;
}