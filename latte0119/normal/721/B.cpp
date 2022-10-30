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

int func(int n,int k){
    return n+(n-1)/k*5;
}

signed main(){
    int N,K;
    cin>>N>>K;
    int cnt[111]={};
    int cr=0;
    string S[100];
    rep(i,N){
        cin>>S[i];
        cnt[S[i].size()]++;
    }

    string ans;
    cin>>ans;
    rep(i,N)if(ans==S[i])cr++;
    int num=0;
    for(int i=1;i<ans.size();i++)num+=cnt[i];
    cout<<func(num+1,K)<<" "<<func(num+cnt[ans.size()]-cr+1,K)<<endl;
    return 0;
}