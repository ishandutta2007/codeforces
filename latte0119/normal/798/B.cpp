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

int N;
string S[55];

int calc(string w){
    int res=0;
    rep(i,N){
        bool flag=false;
        rep(j,w.size()){
            string s=S[i];
            rotate(s.begin(),s.begin()+j,s.end());
            if(s==w){
                res+=j;
                flag=true;
                break;
            }
        }
        if(!flag)return INT_MAX;
    }
    return res;
}

signed main(){
    cin>>N;
    rep(i,N)cin>>S[i];

    int mi=INT_MAX;
    rep(i,S[0].size()){
        string s=S[0];
        rotate(s.begin(),s.begin()+i,s.end());
        chmin(mi,calc(s));
    }

    if(mi==INT_MAX)cout<<-1<<endl;
    else cout<<mi<<endl;
    return 0;
}