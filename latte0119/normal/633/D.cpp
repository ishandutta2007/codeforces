#include<bits/stdc++.h>
using namespace std;

//#define int long long

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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N;
int A[1000];

signed main(){
    scanf("%d",&N);
    rep(i,N)scanf("%d",&A[i]);

    map<int,int>cnt;
    rep(i,N)cnt[A[i]]++;

    int ans=2;
    if(cnt.count(0))chmax(ans,cnt[0]);
    rep(i,N)rep(j,N)if(i!=j){
        int x=A[i],y=A[j];
        if(x==0&&y==0)continue;
        vint v;v.pb(x);v.pb(y);
        cnt[x]--;cnt[y]--;
        while(true){
            int z=x+y;
            if(cnt.count(z)==0||cnt[z]==0)break;
            cnt[z]--;
            v.pb(z);
            x=y;y=z;
        }
        chmax(ans,v.size());
        for(int x:v)cnt[x]++;
    }
    cout<<ans<<endl;
    return 0;
}