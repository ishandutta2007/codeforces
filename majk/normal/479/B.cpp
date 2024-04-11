#include <iostream>
#include <vector>

#define x first
#define y second
using namespace std;

int main() {
    int N,K; cin >> N >> K;
    vector<int> A(N); 
    for (int&a:A) cin >> a;
    vector<pair<int,int>> Q;
    for (int i = 0; i < K; ++i) {
        pair<int,int> LO = {A[0],0}, HI = {A[0],0};
        for (int j = 1; j < N; ++j) {
            LO = min(LO,{A[j],j});
            HI = max(HI,{A[j],j});
        }
        if (LO.x >= HI.x - 1) break;
        Q.emplace_back(HI.y+1,LO.y+1);
        A[LO.y]++;
        A[HI.y]--;
    }

    pair<int,int> LO = {A[0],0}, HI = {A[0],0};
    for (int j = 1; j < N; ++j) {
        LO = min(LO,{A[j],j});
        HI = max(HI,{A[j],j});
    }

    cout << HI.x - LO.x << ' ' << Q.size() << '\n';
    for (auto&q:Q) cout << q.x << ' ' << q.y << '\n';
}