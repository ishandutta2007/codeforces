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

signed main(){
    int N,K;
    string S;
    cin>>N>>K>>S;
    rep(i,S.size()){
        if('z'-S[i]>S[i]-'a'){
            int tmp=min((int)('z'-S[i]),K);
            K-=tmp;
            S[i]+=tmp;
        }
        else{
            int tmp=min((int)(S[i]-'a'),K);
            K-=tmp;
            S[i]-=tmp;
        }
    }

    if(K)cout<<-1<<endl;
    else cout<<S<<endl;
    return 0;
}