#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL N; cin >> N;
        UL x = 1, y = 1;
        string S;
        while (x + y < N + 1) {
            string res;
            cout << "? " << y + 1 << " " << x << " " << N << " " << N << endl;
            cout.flush();
            cin >> res;
            if (res == "BAD") { return; }
            if (res == "YES") { y++; S.push_back('D'); }
            else { x++; S.push_back('R'); }
        }
        x = N; y = N;
        string T;
        while (x + y > N + 1) {
            string res;
            cout << "? 1 1 " << y << " " << x - 1 << endl;
            cout.flush();
            cin >> res;
            if (res == "BAD") { return; }
            if (res == "YES") { x--; T.push_back('R'); }
            else { y--; T.push_back('D'); }
        }
        reverse(T.begin(), T.end());

        cout << "! " << (S + T) << endl;
        cout.flush();
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}