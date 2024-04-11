#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cassert>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<climits>
using namespace std;
typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

#define int long long

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int lcm(int a,int b){
    return a/gcd(a,b)*b;
}

int T,W,B;

void solve(){
    if(W>B)swap(W,B);

    int a=min(min(W,B)-1,T);
    int g=gcd(a,T);
    cout<<a/g<<"/"<<T/g<<endl;
}

signed main(){
    cin>>T>>W>>B;

    if(LLONG_MAX/(W/gcd(W,B))<B){
        solve();
        return 0;
    }

    int l=lcm(W,B);
    int ans=((T+1)/l+1)*min(W,B)-1;

    if((T+1)%l<min(W,B))ans-=min(W,B)-(T+1)%l;

    int g=gcd(ans,T);
    ans/=g;
    T/=g;
    cout<<ans<<"/"<<T<<endl;
    return 0;
}