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

int n;
int a[300000];

signed main(){
    scanf("%lld",&n);
    rep(i,n)scanf("%lld",&a[i]);
    sort(a,a+n);
    int sum=0;
    for(int i=0;i<n-1;i++)sum+=(i+2)*a[i];
    sum+=n*a[n-1];
    printf("%lld\n",sum);
    return 0;
}