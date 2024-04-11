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

int N,M;
string name[100];
int id[100];
bool ex[100][100];
string str[100];
int getid(string s){
    int tmp=find(name,name+N,s)-name;
    if(tmp==N)return -1;
    return tmp;
}

int dp[111][111];

bool latte(char c){
    return !isdigit(c)&&!isalpha(c);
}

void solve(){
    memset(ex,0,sizeof(ex));
    cin>>N;
    rep(i,N)cin>>name[i];

    cin>>M;
    cin.ignore();
    rep(i,M){
        string s;getline(cin,s);
        int t=find(all(s),':')-s.begin();
        id[i]=getid(s.substr(0,t));
        s=s.substr(t+1,s.size()-t-1);
        str[i]=s;
        for(int j=0;j<s.size();j++){
            if(j&&!latte(s[j-1]))continue;
            int r=j;
            while(r<s.size()&&!latte(s[r]))r++;
            int tmp=getid(s.substr(j,r-j));
            if(tmp!=-1)ex[i][tmp]=true;
        }
    }

    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++){
        if(id[0]!=-1&&id[0]!=i)continue;
        if(ex[0][i])continue;
        dp[1][i]=0;
    }
    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            if(id[i]!=-1&&id[i]!=j)continue;
            if(ex[i][j])continue;
            for(int k=0;k<N;k++){
                if(k==j)continue;
                if(dp[i][k]>=0)dp[i+1][j]=k;
            }
        }
    }

    vint ans;
    int t=-1;
    rep(i,N)if(dp[M][i]>=0)t=i;
    for(int i=M;i>0;i--){
        if(t==-1){
            cout<<"Impossible"<<endl;
            return;
        }
        ans.pb(t);
        t=dp[i][t];
    }
    reverse(all(ans));
    rep(i,M){
        cout<<name[ans[i]]<<":"<<str[i]<<endl;
    }
}

signed main(){
    int T;cin>>T;
    while(T--)solve();
    return 0;
}