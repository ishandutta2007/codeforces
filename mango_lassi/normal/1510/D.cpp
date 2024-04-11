#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 998244353
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
typedef long double LL;

typedef array<int,10> State;

vi D[10];
int mark[10][10];
LL s[10][10];
int B[10];
int n,d; 

State ans; LL ANS;

void dfs(int dep,State S,LL pro,int last)
{
    if(dep==-1)
    {
        int sum=0,s2=0,s5=0;
        rep(i,0,9) if(D[i].size()) sum+=mark[i][S[i]];
        rep(i,0,9) if(D[i].size() && i%2==0) s2+=mark[i][S[i]];
        rep(i,0,9) if(D[i].size() && i%5==0) s5+=mark[i][S[i]];
        if(sum==0) return;
        if(d%2==0 && s2==0) return;
        if(d%5==0 && s5==0) return;
        //rep(i,0,9) fprintf(stderr,"%d%c",S[i]," \n"[i==9]);
        //rep(i,0,9) rep(j,0,9) fprintf(stderr,"%d%c",mark[i][j]," \n"[j==9]);
        //fprintf(stderr,"?? %d %d %d\n",sum,s2,s5);
        if(last==d && chmax(ANS,pro)) ans=S;
        return;
    }
    if(D[dep].empty()) dfs(dep-1,S,pro,last);
    rep(i,0,9) if(s[dep][i]!=0) 
    {
        State NS=S;
        NS[dep]=i;
        dfs(dep-1,NS,pro*s[dep][i],last*i%10);
    }
}

int main()
{
    scanf("%d%d",&n,&d); 
    rep(i,1,n) 
    {
        int x; scanf("%d",&x);
        D[x%10].pb(x);
    }
    if(d%2==0)
    {
        int sum=0;
        rep(i,0,9) if(i%2==0) sum+=D[i].size();
        if(sum==0) return puts("-1"),0;
    }
    else rep(i,0,9) if(i%2==0) D[i].clear();
    if(d%5==0)
    {
        int sum=0;
        rep(i,0,9) if(i%5==0) sum+=D[i].size();
        if(sum==0) return puts("-1"),0;
    }
    else rep(i,0,9) if(i%5==0) D[i].clear();

    memset(mark,-1,sizeof mark);
    rep(i,0,9) sort(D[i].begin(),D[i].end(),greater<int>());
    vi la{0,1,6,1,6,5,6,1,6,1};
    rep(i,0,9) if(D[i].size())
    {
        int b=i,N=D[i].size();
        mark[i][la[i]]=0;
        rep(j,1,N) 
        {
            mark[i][b]=j;
            b=b*i%10;
        }
        int mn=N+1,base=-1;
        rep(x,0,9) if(mark[i][x]!=-1 && chmin(mn,mark[i][x])) base=x;
        //fprintf(stderr,"?! %d, %d %d %d\n",i,base,N,mn);
        s[i][base]=1; //B[i]=mn;

        rep(j,mn+1,N)
        {
            s[i][base*i%10]=s[i][base]*D[i][j-1];
            base=base*i%10;
        }
        //rep(j,0,9) if(s[i][j]) fprintf(stderr,"? %d, %d: %lld, %d\n",i,j,(ll)s[i][j],mark[i][j]);
    }
    ans[0]=-1;
    dfs(9,State{},1,1);
    if(ans[0]==-1) return puts("-1"),0;
    int cnt=0;
    rep(i,0,9) if(D[i].size()) cnt+=mark[i][ans[i]];
    printf("%d\n",cnt);
    vi A;
    rep(i,0,9) rep(j,0,mark[i][ans[i]]-1) A.pb(D[i][j]);
    rep(i,0,cnt-1) printf("%d%c",A[i]," \n"[i==cnt-1]);
    return 0;
}