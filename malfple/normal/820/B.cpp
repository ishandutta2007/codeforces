#include <iostream>
#include <cstdio>

#include <cstring>
#include <string>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define repp(i,a,b,d) for(int i=a;i<=b;i+=d)
#define rep(i,a,b) repp(i,a,b,1)
#define revv(i,a,b,d) for(int i=a;i>=b;i-=d)
#define rev(i,a,b) revv(i,a,b,1)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

//end of macro

int n,a;

typedef pair<double,double> pdd;
vector<pdd>vec;

double dist(double a, double b, double c, double d){
    return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

inline double len(double a, double b){
    return sqrt(a*a + b*b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n>>a;

    double deg = 360.0/n;

    rep(i,1,n){
        if(i==1){
            vec.pb(mp(1000,0));
        }else{
            double turnd = deg*(i-1);
            turnd *= M_PI / 180.0;
            double x = 1000 * cos(turnd);
            if(x < 1e-6 && -x < 1e-6)x = 0;
            double y = 1000 * sin(turnd);
            if(y < 1e-6 && -y < 1e-6)y = 0;
            vec.pb(mp(x,y));
        }
    }

    //rep(i,0,n-1)cout << vec[i].ff << " " << vec[i].ss << endl;

    int f = 2;
    double ans = 1000000;
    int b,c;
    rep(i,1,n-2){
        if(f <= i)f = i+1;
        while(1){
            double angle1 = acos((1000-vec[i].ff)/len(vec[i].ff-1000, vec[i].ss)) * 180 / M_PI;
            double angle2 = acos((1000-vec[f].ff)/len(vec[f].ff-1000, vec[f].ss)) * 180 / M_PI;
            if(vec[i].ss < 0)angle1 *= -1;
            if(vec[f].ss < 0)angle2 *= -1;

            double angle = angle1-angle2;
            //printf("%d %d %lf\n",i,f,angle);
            double tmp = angle;
            angle -= a;
            if(angle < 0)angle *= -1;

            if(angle < ans){
                ans = angle;
                b = i;
                c = f;
                //printf("%d %d\n",i,f);
            }

            if(tmp > a || f >= n-1){
                break;
            }else{
                f++;
            }
        }
    }

    //cout << ans << endl;
    cout << b+1 << " 1 " << c+1 << endl;

    return 0;
}