#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#define x first
#define y second
#define ll long long
#define ld long double
#define pii pair<int,int>
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
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

int A,B;
int F1[1001][1001];
int F2[1001][1001];

vector<int> P,U,D;
void calc(int N0, int N1, int F[][1001]) {
    for (int p = N0; p < N1; p++) {
		int jmax = min(p-N0+1, B);
        int imax = min(p-N0+1, A);
        for (int i = imax; i >= 1; i--) {
			for (int j = jmax; j >= 1; j--) {
                F[i][j] = max(F[i][j], F[i-1][j-1] + D[p]);
                F[i][j] = max(F[i][j], F[i-1][j] + P[p]);
                F[i][j] = max(F[i][j], F[i][j-1] + U[p]);
            }
            F[i][0] = max(F[i][0], F[i-1][0] + P[p]);
        }
        for (int j = jmax; j >= 1; j--) {
            F[0][j] = max(F[0][j], F[0][j-1] + U[p]);
        }
    }


}

int main(int,char**) {
    ios_base::sync_with_stdio(false);

    int N; 
    cin >> N >> A >> B;
    P.resize(N); U.resize(N); D.resize(N);

    for (int i = 0; i < N; i++) {
        int a,b;char c; cin >> a >> c >> b; P[i] = 1000000*a + 1000*b;
    }
    for (int i = 0; i < N; i++) {
        int a,b;char c; cin >> a >> c >> b; U[i] = 1000000*a + 1000*b;
    }
    for (int i = 0; i < N; i++) {
        D[i] = P[i]+U[i]-(P[i]/1000)*(U[i]/1000);
    }

    calc(0, N/2, F1);
    calc(N/2, N, F2);

    int sol = 0;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (A-i >= 0 && A-i <= 1000 && B-j >= 0 && B-j <= 1000) {
                sol = max(sol, F1[i][j] + F2[A-i][B-j]);
            }
        }
    }

    printf("%d.%06d\n", sol/1000000, sol%1000000);
}