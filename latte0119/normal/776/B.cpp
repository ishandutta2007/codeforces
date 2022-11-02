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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

bool f[111111];

signed main(){
    fill_n(f,111111,1);
    f[0]=f[1]=0;
    for(int i=2;i<111111;i++){
        if(!f[i])continue;
        for(int j=i+i;j<111111;j+=i)f[j]=0;
    }

    int n;scanf("%lld",&n);

    if(n<=2)puts("1");
    else puts("2");
    rep(i,n){
        printf("%lld ",2-(int)f[i+2]);
    }puts("");
    return 0;
}