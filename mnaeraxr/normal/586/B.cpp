#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100;

int v1[maxn];
int v2[maxn];
int cur[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 2; i <= n; ++i){
        cin >> v1[i];
        v1[i] += v1[i - 1];
    }

    for (int i = 1; i < n; ++i)
        cin >> v2[i];

    for (int i = n - 1; i >= 1; --i)
        v2[i] += v2[i + 1];


    for (int i = 1; i <= n; ++i){
        cin >> cur[i];
        cur[i] += v1[i] + v2[i];
    }

    sort(cur + 1, cur + 1 + n);

    cout << cur[1] + cur[2] << endl;

    return 0;
}