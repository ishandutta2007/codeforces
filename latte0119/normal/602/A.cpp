#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int get(){
    int n,b;
    scanf("%lld%lld",&n,&b);
    int ret=0;
    rep(i,n){
        int a;
        scanf("%lld",&a);
        ret=ret*b+a;
    }

    return ret;
}

signed main(){
    int X=get();
    int Y=get();

    if(X>Y)puts(">");
    else if(X<Y)puts("<");
    else puts("=");
    return 0;
}