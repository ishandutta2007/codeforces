#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

int mycount(int64 u){
    int ans = 0;

    while (u){
        ans += u & 1;
        u >>= 1;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> T(n + 1), P(n + 1);

    vector<int> C(2);

    for (int i = 1; i <= n; ++i){
        int64 u; cin >> u;
        T[i] = mycount(u);
        P[i] = T[i] + P[i - 1];

        C[ P[i] & 1 ]++;
    }

    int64 answer = 0;

    for (int i = 1; i <= n; ++i){
        vector<int> D = C;

        int sum = 0, mx = 0;

        for (int j = i; j <= min(i + 65, n); ++j){
            D[P[j] & 1]--;

            sum += T[j];
            mx = max(mx, T[j]);

            if (sum % 2 == 0 && 2 * mx <= sum){
                answer++;
            }
        }

        answer += D[P[i - 1] & 1];

        C[P[i] & 1]--;
    }

    cout << answer << endl;

    return 0;
}