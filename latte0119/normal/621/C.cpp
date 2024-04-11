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

int n,p;
int l[100000],r[100000];
signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>n>>p;
    rep(i,n)cin>>l[i]>>r[i];

    double ans=0;
    rep(i,n){
        int j=(i+1)%n;
        int di=r[i]-l[i]+1,ni=r[i]/p-(l[i]-1)/p;
        int dj=r[j]-l[j]+1,nj=r[j]/p-(l[j]-1)/p;
        int tmp=(di-ni)*(dj-nj);
        ans+=1.0*(di*dj-tmp)/(di*dj);
    }

    printf("%.20lf\n",ans*2000);
    return 0;
}