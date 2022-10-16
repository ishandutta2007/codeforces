#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 300000 + 10;

int coef[maxn];
int pos[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    k += 1;

    int64 answer = 0;

    set<pii> val;
    int t = 0;


    for (int i = 1; i <= n; ++i){
        cin >> coef[i];
        val.insert(pii(coef[i], i));

        if (i >= k){
            pos[val.rbegin()->second] = t++;
            val.erase(*val.rbegin());
        }
    }

    while (!val.empty()){
        pos[val.rbegin()->second] = t++;
        val.erase(*val.rbegin());
    }

    for (int i = 1; i <= n; ++i)
        answer += 1LL * coef[i] * (pos[i] + k - i);

    cout << answer << endl;

    for (int i = 1; i <= n; ++i)
        cout << pos[i] + k << " \n"[i == n];

    return 0;
}