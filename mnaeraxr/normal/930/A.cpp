#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int h[maxn];
int f[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    f[0] = 1;

    for (int i = 2; i <= n; ++i){
        int p; cin >> p;

        h[i] = h[p] + 1;
        f[h[i]] ^= 1;
    }

    int answer = 0;

    for (int i = 0; i <= n; ++i)
        answer += f[i];

    cout << answer << endl;


    return 0;
}