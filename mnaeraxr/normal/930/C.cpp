#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int val[maxn];
int A[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;

        val[a]++;
        val[b + 1]--;
    }

    for (int i = 2; i <= m; ++i)
        val[i] += val[i - 1];

    vector<int> lis;

    for (int i = 1; i <= m; ++i){
        int p = upper_bound(lis.begin(), lis.end(), val[i]) - lis.begin();
        if (p == lis.size())
            lis.push_back(val[i]);
        else
            lis[p] = val[i];

        A[i] = lis.size();
    }

    int answer = 0;
    lis.clear();

    for (int i = m; i >= 1; --i){
        int p = upper_bound(lis.begin(), lis.end(), val[i]) - lis.begin();
        if (p == lis.size())
            lis.push_back(val[i]);
        else
            lis[p] = val[i];

        int x = A[i - 1] + lis.size();
        answer = max(x, answer);
    }

    cout << answer << endl;

    return 0;
}