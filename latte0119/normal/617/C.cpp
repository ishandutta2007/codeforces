#include<iostream>
#include<algorithm>
#include<vector>
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

int N,x1,y1,x2,y2;
int d1[2001],d2[2001];
signed main(){
    cin>>N>>x1>>y1>>x2>>y2;
    rep(i,N){
        int x,y;cin>>x>>y;
        d1[i]=(x-x1)*(x-x1)+(y-y1)*(y-y1);
        d2[i]=(x-x2)*(x-x2)+(y-y2)*(y-y2);
    }

    int ans=1145141919810893ll;
    rep(i,N+1){
        int ma=0;
        rep(j,N)if(d1[j]>d1[i])chmax(ma,d2[j]);
        chmin(ans,d1[i]+ma);
    }
    cout<<ans<<endl;
    return 0;
}