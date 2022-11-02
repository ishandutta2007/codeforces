#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef complex<double>Point;

Point A,B,T;

inline void get(Point &p){
    double x,y;
    scanf("%lf%lf",&x,&y);
    p=Point(x,y);
}

int N;
Point P[100000];

signed main(){
    get(A);get(B);get(T);
    scanf("%lld",&N);
    rep(i,N)get(P[i]);

    double base=0;
    rep(i,N)base+=abs(P[i]-T)*2;

    vector<pair<double,int>>vecA,vecB;
    rep(i,N){
        vecA.pb(make_pair(abs(P[i]-A)-abs(P[i]-T),i));
        vecB.pb(make_pair(abs(P[i]-B)-abs(P[i]-T),i));
    }
    sort(all(vecA));
    sort(all(vecB));


    double mi=1e16;

    //A
    chmin(mi,base+vecA[0].first);

    //B
    chmin(mi,base+vecB[0].first);

    //A&&B
    if(N>=2){
        rep(i,2){
            rep(j,2){
                if(vecA[i].second==vecB[j].second)continue;
                chmin(mi,base+vecA[i].first+vecB[j].first);
            }
        }
    }
    printf("%.20f\n",mi);
    return 0;
}