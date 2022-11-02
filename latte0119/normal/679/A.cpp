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

bool f[111];
vint ps;
signed main(){
    fill_n(f,111,true);
    f[0]=f[1]=false;

    for(int i=2;i<100;i++){
        if(!f[i])continue;
        ps.pb(i);
        for(int j=i*2;j<100;j+=i)f[j]=false;
    }

    int cnt=0;
    int v=-1;
    rep(i,4){
        printf("%lld\n",ps[i]);
        fflush(stdout);
        char t[10];
        scanf("%s",t);
        if(t[0]=='y')cnt++,v=ps[i];
    }

    if(cnt==0){
        puts("prime");
        fflush(stdout);
        return 0;
    }

    if(v!=-1){
        printf("%lld\n",v*v);
        fflush(stdout);
        char t[10];
        scanf("%s",t);
        if(t[0]=='y')cnt++;
    }

    if(cnt>1){
        puts("composite");
        fflush(stdout);
        return 0;
    }

    cnt=0;
    rep(i,15){
        printf("%lld\n",ps[i]);
        fflush(stdout);
        char t[10];
        scanf("%s",t);
        if(t[0]=='y')cnt++;
    }

    if(cnt>1){
        puts("composite");
    }
    else{
        puts("prime");
    }
    fflush(stdout);
    return 0;
}