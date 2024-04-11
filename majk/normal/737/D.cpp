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

vector<int> P;
int N;
#define G 2200
#define H 200
#define I 100
int mem[G][H][I];

int play(bool turn, int l, int r, int k) {
    if (l + r + k > N) { return P[l] - (P[N] - P[N-r]); }
    if (turn) {
        int &m = mem[l][r-l+I][k];
        if (m != MOD) return m;
    }


    int a = turn ? play(!turn, l+k, r, k) : play(!turn, l, r+k, k);
    if (l + r + k < N) {
        if (turn) {
            a = max(a, play(!turn, l+k+1, r, k+1));
        } else {
            a = min(a, play(!turn, l, r+k+1, k+1));
        }
    }

    if (turn) {
        mem[l][r-l+I][k] = a;
    }
    
    return a;
}


int main(int,char**) {
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < G; i++) {
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < I; k++) {
                mem[i][j][k] = MOD;
            }
        }
    }

    cin >> N;
    vector<int> A(N);
    rv(A);
    P.resize(N+1); P[0] = 0;
    for (int i = 0; i < N; i++) {
        P[i+1] = P[i] + A[i];
    }

    cout << play(true, 0, 0, 1) << endl;
}