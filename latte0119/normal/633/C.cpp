#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef long long ll;
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

struct node{
    node *to[26];
    int val;
    node(){
        rep(i,26)to[i]=(node *)NULL;
        val=-1;
    }
};

void insert(node *t,string &str,int i,int j){
    if(i==str.size()){
        t->val=j;
        return;
    }
    if(t->to[str[i]-'a']==NULL){
        t->to[str[i]-'a']=new node();
    }
    insert(t->to[str[i]-'a'],str,i+1,j);
}

int N,M;
string S;
string T[100000];
string TT[100000];
node *root;

char tmp[1000010];

bool dp[10010];
int prev[10010];
signed main(){
    root=new node();
    scanf("%d",&N);
    scanf("%s",tmp);S=tmp;
    scanf("%d",&M);
    rep(i,M){
        scanf("%s",tmp);
        T[i]=tmp;
        TT[i]=T[i];
        reverse(all(TT[i]));
        rep(j,TT[i].size())TT[i][j]=tolower(TT[i][j]);
        insert(root,TT[i],0,i);
    }
    dp[0]=true;
    memset(prev,-1,sizeof(prev));
    rep(i,N){
        if(!dp[i])continue;
        node *t=root;
        for(int j=i;j<N;j++){
            int c=S[j]-'a';
            if(t->to[c]==NULL)break;
            t=t->to[c];
            if(t->val!=-1){
                dp[j+1]=true;
                prev[j+1]=t->val;
            }
        }
    }

    int cur=N;
    vint lis;
    while(cur){
        int t=prev[cur];
        lis.pb(t);
        cur-=T[t].size();
    }
    reverse(all(lis));
    rep(i,lis.size())printf("%s ",T[lis[i]].c_str());
    puts("");
    return 0;
}