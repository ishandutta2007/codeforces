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

    int n;
    int64 k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    int p = 0;

    while (p < n && a[p] == b[p])
        p++;

    int64 answer = a.length() + b.length() - p;

    if (a == b){
        cout << n << endl;
        return 0;
    }

    if (k == 1){
        cout << n << endl;
        return 0;
    }

    if (k == 2){
        cout << answer << endl;
        return 0;
    }

    answer = p + 2;
    int64 active = 2;

    // cout << "answer: " << answer << endl;

    for (int i = p + 1; i < n; ++i){
        active *= 2;

        if (a[i] != 'a') active--;
        if (b[i] != 'b') active--;

        active = min(active, k);

        answer += active;

        // cout << i << " " << active << " " << answer << endl;
    }

    cout << answer << endl;

    return 0;
}