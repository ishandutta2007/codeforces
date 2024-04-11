#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int64> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

struct pack {
    int64 i0, i1, d;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<pii> A(n);

    vector<int64> fin(n);

    for (int i = 0; i < n; ++i){
        cin >> A[i].first;
        A[i].second = i + 1;
    }

    for (int i = 0; i < n; ++i)
        cin >> fin[i];

    sort(A.begin(), A.end());
    sort(fin.begin(), fin.end());

    vector<pack> answer;

    vector<int> P, N;

    for (int i = 0; i < n; ++i){
        if (A[i].first < fin[i]) P.push_back(i);
        if (A[i].first > fin[i]) N.push_back(i);
    }

    int a = 0, b = 0;

    while (a < P.size() && b < N.size()){
        int i = P[a], j = N[b];

        if (A[i].first > A[j].first){
            cout << "NO" << endl;
            return 0;
        }

        // cout << i + 1 << " " << j + 1 << endl;
        // cout << A[i].first << " " << A[j].first << endl;
        // cout << fin[i] << " " << fin[j] << endl;
        // cout << endl;
        // cout.flush();

        int di = fin[i] - A[i].first;
        int dj = A[j].first - fin[j];
        
        if (fin[i] > fin[j]){
            cout << "NO" << endl;
            return 0;
        }

        int d = min(di, dj);

        assert(d > 0);

        A[i].first += d;
        A[j].first -= d;

        answer.push_back({A[i].second, A[j].second, d});

        if (d == di) a++;
        if (d == dj) b++;
    }

    if (a == P.size() && b == N.size()){
        cout << "YES" << endl;
        cout << answer.size() << endl;

        for (auto x : answer)
            cout << x.i0 << " " << x.i1 << " " << x.d << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}