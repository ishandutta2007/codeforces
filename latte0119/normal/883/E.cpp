#include<bits/stdc++.h>
using namespace std;

#define int long long

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

signed main(){
    int L;cin>>L;
    string S;cin>>S;

    int p=(1<<26)-1;
    int N;cin>>N;

    bool b[26]={};
    rep(i,S.size()){
        if(S[i]!='*')b[S[i]-'a']=1;
    }

    while(N--){
        bool ok=true;
        int r=0;
        string s;cin>>s;
        rep(i,S.size()){
            if(S[i]!='*'){
                if(S[i]!=s[i])ok=false;
            }
            else{
                int c=s[i]-'a';
                if(b[c])ok=false;
                r|=1<<c;
            }
        }
        if(ok)p&=r;
    }

    cout<<__builtin_popcountll(p)<<endl;
    return 0;
}