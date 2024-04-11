#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef unsigned int ui;

#define x first
#define y second

template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}

template<typename F> double bshd(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}


int main() {
    int N, L; cin >> N >> L;
    vector<int> X(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> B[i];
    }

    vector<int> Best;

    bsld(0, 1e4, [&](double d) {
            vector<pair<double,int>> E(N+1, {1e40, -1});
            E[0] = {0,-1};
            for (int i = 0; i < N; ++i) {
                for (int j = i; j < N; ++j) {
                    double f = E[i].x + sqrt(abs(X[j] - (i?X[i-1]:0) - L)) - d * B[j];
                    E[j+1] = min(E[j+1], {f,i}); 
                }
            }
            
            if (E[N].x <= 0) {
                Best.clear();
                int n = N;
                while (n != 0) {
                    Best.push_back(n);
                    n = E[n].y;
                }
                return true;
            } else {
                return false;
            }
            
            });
    reverse(Best.begin(),Best.end());
    for (int i = 0; i < Best.size(); ++i) {
        cout << Best[i] << " \n"[i==Best.size()-1];
    }

}