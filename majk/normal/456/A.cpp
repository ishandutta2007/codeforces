#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; ++i) {
        int a,b; cin >> a >> b;
        A[i] = {a,b};
    }
    sort(A.begin(),A.end());
    for (int i = 1; i < N; ++i) {
        if (A[i].second < A[i-1].second) {
            cout << "Happy Alex\n";
            return 0;
        }
    }
    cout << "Poor Alex\n";
}