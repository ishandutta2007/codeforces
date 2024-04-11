#include<bits/stdc++.h>
using namespace std;

//#define int long long

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

signed main(){
    int n;scanf("%d",&n);

    int c=0;rep(i,n)rep(j,n)if((i+j)%2==0)c++;
    printf("%d\n",c);

    rep(i,n){
        rep(j,n){
            if((i+j)&1)printf(".");
            else printf("C");
        }
        puts("");
    }
    return 0;
}