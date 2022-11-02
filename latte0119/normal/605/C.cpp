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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int n,p,q;
int a[111111],b[111111];

double get(double y1){
    double y2=1145141919.0;
    rep(i,n)chmin(y2,(1.0-y1*a[i])/b[i]);
    return y1*p+y2*q;
}

signed main(){
    scanf("%d%d%d",&n,&p,&q);
    rep(i,n)scanf("%d%d",&a[i],&b[i]);

    double lb=0,ub=1145141919.0;
    rep(i,n)chmin(ub,1.0/a[i]);
    rep(t,50){
        double m1=(lb*2+ub)/3,m2=(lb+ub*2)/3;

        double v1=get(m1),v2=get(m2);
        if(v1<v2)lb=m1;
        else ub=m2;
    }

    printf("%.20f\n",get((lb+ub)/2));
    return 0;
}