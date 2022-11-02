#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int f(int x){
    if(x==0)return 1;
    int ret=0;
    while(x){
        x/=7;
        ret++;
    }
    return ret;
}


signed main(){
    int N,M;
    cin>>N>>M;

    int n=f(N-1),m=f(M-1);
    if(n+m>7){
        puts("0");
        return 0;
    }

    int p[7];
    rep(i,7)p[i]=i;

    int ans=0;
    do{
        int x=0,y=0;
        rep(i,n)x=x*7+p[i];
        rep(i,m)y=y*7+p[n+i];
        if(x<N&&y<M)ans++;
    }while(next_permutation(p,p+7));

    for(int i=1;i<=7-n-m;i++)ans/=i;
    cout<<ans<<endl;
    return 0;
}