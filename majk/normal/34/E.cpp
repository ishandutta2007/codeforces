#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;
#define x first
#define y second

constexpr double EPS = 1e-15;

int main() {
    int N; cin >> N;
    double T; cin >> T;
    vector<double> X(N), V(N), M(N);
    for (int i = 0; i < N; ++i) cin >> X[i] >> V[i] >> M[i];
    vector<pair<int,int>> P(N);
    for (int i = 0; i < N; ++i) {
        P[i] = {X[i], i};
    }
    sort(P.begin(),P.end());

    while (true) {
        pair<double, int> C = {1e18, -1};
        for (int i = 0; i < N-1; ++i) {
            double d = X[P[i+1].y]-X[P[i].y];
            double v = V[P[i].y], w = V[P[i+1].y];
            if (w + EPS < v) C = min(C, {d/(v-w), i});
        }
        if (C.x > T) break;

        T -= C.x;
        for (int i = 0; i < N; ++i) { 
            X[i] += V[i] * C.x;
            if (V[i] < 0) X[i] += EPS;
            else X[i] -= EPS;
        }
        int i = P[C.y].y, j = P[C.y+1].y;
        double m1 = M[i], m2 = M[j], v1 = V[i], v2 = V[j];
        double w1 = ((m1-m2) * v1 + 2 * m2 * v2) / (m1+m2);
        double w2 = ((m2-m1) * v2 + 2 * m1 * v1) / (m1+m2);
        V[i] = w1;
        V[j] = w2;
    }
    
    for (int i = 0; i < N; ++i) { 
        X[i] += V[i] * T;
    }

    cout << fixed << setprecision(10);
    for (int i = 0; i < N; ++i) {
        cout << X[i] << endl;
    }
}