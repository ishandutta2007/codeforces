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

string T="AGCT";
int cnt[4];

signed main(){
    int N;
    string S;
    cin>>N>>S;
    rep(i,S.size()){
        if(S[i]=='?')continue;
        cnt[find(all(T),S[i])-T.begin()]++;
    }

    int to=(N+3)/4;
    int cur=0;
    for(int i=0;i<N;i++){
        if(S[i]!='?')continue;
        while(cur<4&&cnt[cur]>=to)cur++;
        if(cur<4){
            cnt[cur]++;
            S[i]=T[cur];
        }
    }

    rep(i,4)if(cnt[i]!=to){
        cout<<"==="<<endl;
        return 0;
    }
    cout<<S<<endl;
    return 0;
}