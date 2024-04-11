#include <string>
#include <iostream>

using namespace std;
int main() {
    string A, B; cin >> B >> A;
    int N = A.size(), M = B.size();
    int ones = 0;
    for (int i = 0; i < N-M; ++i) {
        ones += A[i] == '1';
    }
    long long ans = 0;
    for (int i = 0; i < M; ++i) {
        ones += A[i+N-M] == '1';
        ans += B[i]=='0' ? ones : (N-M+1)-ones;       
        ones -= A[i] == '1';
    }
    cout << ans << endl;
}