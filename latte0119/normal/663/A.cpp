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

signed main(){
    int n;
    char c;
    vint a;
    while(true){
        scanf(" %c",&c);
        if(c=='?')continue;
        if(c=='=')break;
        if(c=='+')a.pb(1);
        else a.pb(-1);
    }
    scanf("%lld",&n);

    int up=n,down=1;
    vint ans(a.size()+1);
    ans[0]=1;
    rep(i,a.size()){
        if(a[i]==1){
            ans[i+1]=1;
            up+=n;
            down+=1;
        }
        else{
            ans[i+1]=n;
            up-=1;
            down-=n;
        }
    }

    if(up<n||down>n){
        puts("Impossible");
        return 0;
    }

    int hoge=down;
    rep(i,ans.size()){
        if(i==0||a[i-1]==1){
            ans[i]+=min(n-1,n-hoge);
            hoge=hoge-1+ans[i];
        }
        else{
            ans[i]-=min(n-1,n-hoge);
            hoge=hoge+n-ans[i];
        }
    }   

    puts("Possible");
    printf("%lld",ans[0]);
    reps(i,1,ans.size())printf(" %c %lld",a[i-1]==1?'+':'-',ans[i]);
    printf(" = %lld\n",n);
    return 0;
}