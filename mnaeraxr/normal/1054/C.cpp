#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> l(n), r(n);

    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> l[i];
    for (int i = 0; i < n; ++i) cin >> r[i];

    for (int i = 0; i < n; ++i){
        A[i] = n  - l[i] - r[i];
    }

    for (int i = 0; i < n; ++i){

        for (int j = 0; j < n; ++j)
            if (A[j] > A[i]){
                if (j < i) l[i]--;
                else r[i]--;
            }

        if (l[i] | r[i]){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i){
        cout << A[i] << " \n"[i + 1 == n];
    }
}