#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

#ifndef MDEBUG
#define NDEBUG
#endif

#define x first
#define y second
#define ll long long
#define ld double
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pss pair<string,string>
#define psi pair<string,int>
#define pis pair<int,string>
#define psl pair<string,ll>
#define pls pair<ll,string>
#define wh(x) (x).begin(),(x).end()
#define ri(x) int x;cin>>x;
#define rii(x,y) int x,y;cin>>x>>y;
#define rl(x) ll x;cin>>x;
#define rv(v) for(auto&_cinv:v) cin>>_cinv;
#define wv(v) for(auto&_coutv:v) cout << _coutv << ' '; cout << endl;
#define ev(v) for(auto&_cerrv:v) cerr << _cerrv << ' '; cerr << endl;
#define MOD 1000000007

namespace std { 
template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
// auto fraclt = [](auto&a,auto&b) { return (ll)a.x * b.y < (ll)b.x * a.y; };
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }
template<typename T> void fracn(pair<T,T>&a) {auto g=gcd(a.x,a.y);a.x/=g;a.y/=g;}
template<typename T> struct Index { int operator[](const T&t){auto i=m.find(t);return i!=m.end()?i->y:m[t]=m.size();}int s(){return m.size();} unordered_map<T,int> m; };

const double PI = atan(1)*4;

int main(int,char**) {
    rl(x0);rl(y0);rl(v);rl(T);
    ld R = 1.0*v*T; 

    vector<pair<ld,int>> in;

    bool all = false;
    ri(N);
    for (int i = 0; i < N; i++) {
        rl(x);rl(y);rl(r);
        ll dsq = (x-x0)*(x-x0)+(y-y0)*(y-y0);
        ld off;
        if (dsq <= r*r) {
            // very close
            all = true;
            break;
        }

        ld d = sqrt(dsq);
        if (R+r <= d) {
            // too far away
            continue;
        } 
            
        ld tng = sqrt(dsq - r*r);
        if (tng <= R) {
            // too close
            off = asin(1.0 * r / d);
        } else {
            ld a = (R*R - 1.0*r*r + dsq) / (2*d);
            off = acos(a / R);
        }

        ld cen = atan2(y-y0,x-x0);

        if (cen-off < -PI) 
        {
            in.push_back({-PI,1});
            in.push_back({cen+off,-1});
            in.push_back({cen-off+2*PI,1});
            in.push_back({PI,-1});
        } else if (cen+off > PI) {
            in.push_back({-PI,1});
            in.push_back({cen+off-2*PI,-1});
            in.push_back({cen-off,1});
            in.push_back({PI,-1});
        } else {
            in.push_back({cen-off,1});
            in.push_back({cen+off,-1});
        }
    }

    if (all) {
        printf("%.11f\n", 1.0);
    } else {
        sort(wh(in));
        ld ans=0.0, last=-PI;
        int c=0;
        for (auto &p: in) {
            if(c>0) ans += p.x - last;
            c += p.y;
            last = p.x;
        }
        /*while (i < in.size() && j < out.size()) {
            if (j == out.size() || (i < in.size() && in[i] <= out[j])) {
                last = in[i]; 
            } else {
                last = out[j];
            }
                
            if (c > 0) {
                ans += last - ang;
            }

            if (j == out.size() || (i < in.size() && in[i] <= out[j])) {
                ++c;++i;
            } else {--c;++j;}

            ang = last;
        }*/

        printf("%.011f\n", ans / (2*PI));
    }

}