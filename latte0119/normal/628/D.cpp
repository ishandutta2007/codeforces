#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
#define each(i,c) for(auto i=(c).begin();i!=(c).end();i++)
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int M,D;
string A,B;

const int mod=1000000007;
string S;
int memo[2][2][2][2010][2010];

int dfs(int n,int f,int e,int z,int m){
    if(n==S.size())return m==0;
    int &ret=memo[f][e][z][n][m];
    if(ret!=-1)return ret;
    ret=0;
    rep(i,10){
        if(!f&&i>S[n]-'0')break;
        if(e&&i!=D)continue;
        if(((z&&!e)||(!z&&i))&&i==D)continue;
        ret+=dfs(n+1,f|(i!=S[n]-'0'),(z|(i!=0))?1-e:0,z|(i!=0),(m*10+i)%M);
    }
    return ret%=mod;
}

signed main(){
    cin>>M>>D;
    cin>>A>>B;

    memset(memo,-1,sizeof(memo));

    S=B;
    int ans=dfs(0,0,0,0,0);
    memset(memo,-1,sizeof(memo));
    S=A;
    ans-=dfs(0,0,0,0,0);
    bool ok=true;
    rep(i,S.size()){
        if(i&1)ok&=(S[i]-'0')==D;
        else ok&=(S[i]-'0')!=D;
    }
    int m=0;
    rep(i,S.size()){
        m=(m*10+(S[i]-'0'))%M;
    }
    ok&=m==0;
    if(ok)ans++;
    cout<<(ans+mod*10)%mod<<endl;
    return 0;
}