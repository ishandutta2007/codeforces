#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    vector<int> T(n);

    for (int i = 0; i < n; ++i){
        cin >> T[i];
    }

    int a; cin >> a;

    priority_queue<int> pq;

    int64 answer = 0;

    for (int i = 0; i < n; ++i){
        int u; cin >> u;
        pq.push(-u);

        while (k < T[i] && !pq.empty()){
            k += a;
            answer -= pq.top();
            pq.pop();
        }

        if (k < T[i]){
            cout << -1 << endl;
            exit(0);
        }
    }

    cout << answer << endl;

    return 0;
}