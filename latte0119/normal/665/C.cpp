#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

string S;

signed main(){
    cin>>S;
    S+="*";

    for(int i=1;i<S.size();i++){
        if(S[i-1]!=S[i])continue;
        for(S[i]='a';S[i]<='z';S[i]++)if(S[i-1]!=S[i]&&S[i]!=S[i+1])break;
    }
    cout<<S.substr(0,S.size()-1)<<endl;
    return 0;
}