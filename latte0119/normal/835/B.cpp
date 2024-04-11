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

const int INF=1001001001;
const int INFLL=1001001001001001001ll;
const int mod=1000000007;
inline void am(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}


signed main(){
    int N;
    cin>>N;
    string S;cin>>S;
    vint A;rep(i,S.size())A.pb(S[i]-'0');
    sort(all(A));

    int sum=accumulate(all(A),0ll);
    int cur=0;
    while(true){
        if(sum>=N){
            cout<<cur<<endl;
            return 0;
        }
        sum+=9-A[cur];
        cur++;
    }
    return 0;
}