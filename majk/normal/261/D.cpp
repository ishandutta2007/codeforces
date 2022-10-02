#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int K,N,MAXB,T; cin >> K >> N >> MAXB >> T;
   // vector<vector<int>> G(MAXB);
   // for (auto&g:G) g.resize(1+min(MAXB,N));
   // T = min(T, MAXB);
    for (int k = 0; k < K; ++k) {
        vector<int> X(N);
        for (int&x:X) cin >> x;
        vector<int> B(1+min(MAXB,N), MAXB+1);
        B[0] = 0;
        auto mx = B.begin()+2;
        auto prev = mx;
        int R = min(T, min(MAXB, N));
        for (int i = 0; i < R; ++i) {
            for (int x: X) {
                if (x > i) {
                    auto it = lower_bound(B.begin(), mx, x);
                    *it = min(*it, x);
                    mx += (mx == next(it));
                }
            }
            if (prev == mx) break;
            prev = mx;
        }
        cout << mx-B.begin()-2 << endl;
        
        
        /*for (int i = 0; i < N; ++i) { 
            G[i][0] = i; 
            fill(G[i].begin()+1,G[i].end(),MAXB+1); 
        }
        for (int i = 0; i < N; ++i) {
            int x; cin >> x;
            int z = min(MAXB,N);
            for (int k = 0; k < K; ++k) {
                while (G[k][z] >= x) --z;
                G[k][z+1] = min(G[k][z+1], x);
            }
        }*/

        // D[a][b] -- max len of run considering numbers > a, with b runs

/*
        for (int i = 0; i < N; ++i) {
            for (int g:G[i]) cout << g << ' ';
            cout << endl;
        }
        cout << endl;
   */


    }
}