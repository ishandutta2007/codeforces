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

string S;
int dp[3333333];
signed main(){
    for(int i=0;i<26;i++)S+=(char)('a'+i);
    for(int i=0;i<26;i++)S+=(char)('A'+i);
    fill_n(dp,1111111,INT_MAX);
    dp[1]=0;
    for(int i=1;i<1111111;i++){
        for(int j=1;j<=2;j++){
            chmin(dp[i*j+1],dp[i]+1);
        }
    }

    int n;cin>>n;
    string s;
    int cur=0;
    while(n>1){
        if((n-1)&1){
            s+=string(1,S[cur++]);
            n--;
        }
        else{
            s+=string(2,S[cur++]);
            n=(n-1)/2;
        }
    }
    for(int i=0;i<S.size();i++)s+=S[i];
    cout<<s<<" "<<S<<endl;
    return 0;
}