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

int calc(int s,int v,int t){
    return 2*t+s*v;
}

signed main(){
    int s,v1,v2,t1,t2;
    cin>>s>>v1>>v2>>t1>>t2;
    int X=calc(s,v1,t1);
    int Y=calc(s,v2,t2);
    if(X<Y)cout<<"First"<<endl;
    else if(X>Y)cout<<"Second"<<endl;
    else cout<<"Friendship"<<endl;
    return 0;
}