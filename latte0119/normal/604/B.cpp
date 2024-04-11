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

int N,K;
int s[100000];

signed main(){
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);

    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld",&s[i]);

    int n=(N-K)*2;
    int ma=s[N-1];
    rep(i,N-K)ma=max(ma,s[n-i-1]+s[i]);
    printf("%lld\n",ma);
    return 0;
}