#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N); 
    for (int &a:A) cin >> a;
    if (A.back() == 1) {
        cout << "NO\n";
        return 0;
    }
 
    if (N == 1) { cout << "YES\n0\n"; }
    else if (N == 2) {
        if (A[0] == 0) cout << "NO\n";
        else cout << "YES\n1->0\n";
    } else if (A[N-2] == 1) {
        cout << "YES\n";
        for (int i = 0; i < N; ++i) cout << A[i] << (i==N-1?"\n":"->"); 
    } else if (A[N-3] == 0) {
        cout << "YES\n";
        for (int i = 0; i < N-3; ++i) cout << A[i] << "->"; 
        cout << "(0->0)->0\n";
    } else {
        // end is 100
        int a = N-3;
        while (a >= 0 && A[a] == 1) --a;
        if (a == -1) { cout << "NO\n"; return 0; }
        while (a > 0 && A[a-1] == 0) --a;
        cout << "YES\n";
        for (int i = 0; i < a; ++i) cout << A[i] << "->";
        cout << "(0->(";
        for (int i = a+1; i < N-2; ++i) cout << A[i] << "->";
        cout << "0))->0\n";
    }
}