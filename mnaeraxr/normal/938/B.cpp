#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> v(n + 2);

    v[0] = 1;
    v[n+1] = 1000000;

    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    int answer = v[n+1] - v[0];

    for (int i = 0; i <= n; ++i){
        answer = min(answer, max(v[i] - v[0], v[n + 1] - v[i + 1]));
    }

    cout << answer << endl;


    return 0;
}