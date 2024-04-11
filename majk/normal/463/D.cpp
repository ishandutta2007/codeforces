#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<vector<int>> W(K, vector<int>(N));
    vector<vector<int>> B(K, vector<int>(N));
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
            B[i][W[i][j]-1] = j;
        }
    }
    vector<vector<int>> E(N);
    vector<int> D(N,0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool gt = true;
            for (int k = 0; k < K; ++k) {
                gt &= B[k][i] < B[k][j];
            }
            if (gt) {
                D[j]++;
                E[i].push_back(j);
            }
        }
    }

    vector<int> Q;
    for (int i = 0; i < N; ++i) if (D[i]==0) Q.push_back(i);
    vector<int> A(N, 1);
    for (int i = 0; i < N; ++i) {
        for (int v:E[Q[i]]) {
            A[v] = max(A[v], A[Q[i]]+1);
            if (!--D[v]) Q.push_back(v);
        }
    }

    cout << *max_element(A.begin(),A.end()) << endl;
}