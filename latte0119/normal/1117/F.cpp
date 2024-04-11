#include<bits/stdc++.h>
using namespace std;


#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,P;
char str[111111];
int A[17][17];

bool ng[1<<17];

int ei[1<<17];
bool dp[1<<17];
signed main(){
    scanf("%d%d",&N,&P);
    scanf("%s",str);
    rep(i,P)rep(j,P)scanf("%d",&A[i][j]);

    for(int x=0;x<P;x++){
        for(int y=x;y<P;y++){
            if(A[x][y])continue;
            memset(ei,0,sizeof(ei));

            vint lis;
            rep(i,N)if(str[i]=='a'+x||str[i]=='a'+y)lis.pb(i);
            for(int i=0;i+1<lis.size();i++){
                if(x!=y&&str[lis[i]]==str[lis[i+1]])continue;
                int mask=0;
                for(int j=lis[i]+1;j<lis[i+1];j++)mask|=1<<(str[j]-'a');
                ei[mask]=1;
            }

            rep(i,1<<P){
                rep(j,P){
                    if(!(i>>j&1))continue;
                    ei[i]|=ei[i^(1<<j)];
                }
            }
            rep(i,1<<P)if(ei[i]&&!(i>>x&1)&&!(i>>y&1))ng[i]=true;
        }
    }
    /*
    rep(i,1<<P){
        string s;
        rep(j,N){
            if(!(i>>(str[j]-'a')&1))s+=str[j];
        }
        bool ok=true;
        for(int j=0;j+1<s.size();j++)if(!A[s[j]-'a'][s[j+1]-'a'])ok=false;
        if(!ok)ng[i]=true;
    }*/

    dp[0]=true;
    rep(i,1<<P){
        if(!dp[i])continue;
        rep(j,P){
            if(i>>j&1)continue;
            if(ng[i|(1<<j)])continue;
            dp[i|(1<<j)]=true;
        }
    }

    vint cnt(P);rep(i,N)cnt[str[i]-'a']++;

    int ans=N;
    rep(i,1<<P){
        if(!dp[i])continue;
        int sum=0;
        rep(j,P)if(!(i>>j&1))sum+=cnt[j];
        chmin(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}