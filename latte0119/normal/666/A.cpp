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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N;
char S[11111];
int ex[27*26*26];
int dp[11111][2];
int get(int l,int r){
    if(r>N)return -1;
    int x=0;
    for(int i=l;i<r;i++){
        x=x*26+(S[i]-'a');
    }
    if(r-l==2)x+=26*26*26;
    return x;
}
signed main(){
    scanf("%s",S);
    N=strlen(S);

    if(N<=6){
        puts("0");
        return 0;
    }
    if(N==7){
        puts("1");
        printf("%s",S+5);
        return 0;
    }

    ex[get(N-2,N)]=true;
    ex[get(N-3,N)]=true;
    dp[N-2][0]=true;
    dp[N-3][1]=true;
    for(int i=N-4;i>=5;i--){
        int t2=get(i,i+2);
        int t3=get(i,i+3);
        if(t2==get(i+2,i+4))dp[i][0]=dp[i+2][1];
        else dp[i][0]=dp[i+2][0]|dp[i+2][1];
        if(t3==get(i+3,i+6))dp[i][1]=dp[i+3][0];
        else dp[i][1]=dp[i+3][0]|dp[i+3][1];

        if(dp[i][0])ex[t2]=true;
        if(dp[i][1])ex[t3]=true;
    }

    vector<string>vec;
    rep(i,26)rep(j,26)if(ex[26*26*26+i*26+j])vec.pb(string(1,'a'+i)+string(1,'a'+j));
    rep(i,26)rep(j,26)rep(k,26)if(ex[i*26*26+j*26+k])vec.pb(string(1,'a'+i)+string(1,'a'+j)+string(1,'a'+k));
    sort(all(vec));
    printf("%lld\n",(int)vec.size());
    rep(i,vec.size())printf("%s\n",vec[i].c_str());
    return 0;
}