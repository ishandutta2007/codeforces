#include<bits/stdc++.h>
using namespace std;

#define int long long


typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}


int N;
int x1,x2;

vector<pint>vec;

signed main(){
    scanf("%lld",&N);
    scanf("%lld%lld",&x1,&x2);


    rep(i,N){
        int k,b;
        scanf("%lld%lld",&k,&b);
        int l=x1*k+b;
        int m=x2*k+b;
        vec.pb(mp(l,m));
    }

    sort(vec.begin(),vec.end());

    int ma=LLONG_MIN;

    rep(i,N){
        if(vec[i].second<ma){
            puts("YES");
            return 0;
        }
        chmax(ma,vec[i].second);
    }

    puts("NO");
    return 0;
}