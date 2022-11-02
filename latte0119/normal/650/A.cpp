#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
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

int N;
map<int,int>x,y;
map<pint,int>p;

signed main(){
    scanf("%lld",&N);
    rep(i,N){
        int xx,yy;
        scanf("%lld%lld",&xx,&yy);
        x[xx]++;y[yy]++;p[pint(xx,yy)]++;
    }

    int ans=0;
    each(it,x){
        ans+=it->se*(it->se-1)/2;
    }
    each(it,y){
        ans+=it->se*(it->se-1)/2;
    }
    each(it,p){
        ans-=it->se*(it->se-1)/2;
    }

    printf("%lld\n",ans);
    return 0;
}