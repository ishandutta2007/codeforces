#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int lcm(int a,int b){
    return a/gcd(a,b)*b;
}

int N,K;

signed main(){
    scanf("%lld%lld",&N,&K);
    int l=1;
    rep(i,N){
        int c;scanf("%lld",&c);
        c=gcd(c,K);
        l=lcm(l,c);
        l=gcd(l,K);
    }

    if(l==K)puts("Yes");
    else puts("No");
    return 0;
}