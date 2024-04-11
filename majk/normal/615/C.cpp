#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define x first
#define y second
typedef pair<int,int> pii;

int main() {
    string S,T; cin >> S >> T;
    int N = S.size(), M = T.size();
    vector<pii> Ans;
    for (int i = 0; i < M; ) {
        pii B = {0, 0};
        for (int j = 0; j < N; ++j) {
            int l = 0;
            while (j+l < N && i+l < M && S[j+l] == T[i+l]) ++l;
            B = max(B, {l, j+1});
        }

        for (int j = 0; j < N; ++j) {
            int l = 0;
            while (j-l >= 0 && i+l < M && S[j-l] == T[i+l]) ++l;
            B = max(B, {l, -(j+1)});
        }
        if (B.x == 0) {
            cout << "-1\n";
            return 0;
        }
        if (B.y > 0) Ans.push_back({B.y, B.y + B.x - 1});
        else Ans.push_back({-B.y, -B.y - B.x + 1});
        i += B.x;
    }
    cout << Ans.size() << '\n';
    for (pii&ans: Ans) cout << ans.x << ' ' << ans.y << '\n';
}