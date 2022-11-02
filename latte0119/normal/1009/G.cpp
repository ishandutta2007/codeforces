#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

int G[111111];
int N;
int cnt[6];
int cap[64];
int deg[64];


bool check(int n){
    int cut=1001001001;
    rep(i,64){
        chmin(cut,cap[i]+deg[63^i]);
    }
    return cut==n;
}


bool va(int n){
    rep(i,64){
        int sum=0;
        rep(j,6)if(i>>j&1)sum+=cnt[j];
        if(sum!=cap[i])return false;
    }

    rep(i,64){
        int sum=0;
        for(int j=N-n;j<N;j++){
            if(G[j]&i)sum++;
        }
        if(sum!=deg[i])return false;
    }
    return true;
}

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string S;cin>>S;
    N=S.size();
    rep(i,N)cnt[S[i]-'a']++;

    rep(i,64)rep(j,6)if(i>>j&1)cap[i]+=cnt[j];

    fill_n(G,111111,63);
    int M;cin>>M;
    rep(i,M){
        int pos;
        string s;
        cin>>pos>>s;
        pos--;
        G[pos]=0;
        for(auto c:s)G[pos]|=1<<(c-'a');
    }

    rep(i,N){
        rep(j,64)if(j&G[i])deg[j]++;
    }

    if(!check(N)){
        puts("Impossible");
        return 0;
    }

    string ans(N,'a');
    rep(i,N){
        rep(j,64)if(j&G[i])deg[j]--;
        for(int j=0;j<6;j++){
            if(!(G[i]>>j&1))continue;
            if(cnt[j]==0)continue;
            rep(k,64)if(k>>j&1)cap[k]--;
            cnt[j]--;
            if(check(N-i-1)){
                ans[i]='a'+j;
                break;
            }
            cnt[j]++;
            rep(k,64)if(k>>j&1)cap[k]++;
        }
    }

    cout<<ans<<endl;
    return 0;
}