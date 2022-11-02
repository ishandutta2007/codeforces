#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int n;
int idx[200000];

signed main(){
    scanf("%d",&n);
    rep(i,n){
        int a;scanf("%d",&a);idx[--a]=i;
    }
    long long ans=0;
    rep(i,n-1)ans+=max(idx[i+1]-idx[i],idx[i]-idx[i+1]);
    printf("%lld\n",ans);
    return 0;
}