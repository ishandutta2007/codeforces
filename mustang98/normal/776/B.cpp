#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111;

//int m[max_n] = {0};
bool m[max_n][100];
int ans[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 2; i <= n + 1; ++i) {
        int wont = 1;
        while(m[i][wont]) wont++;
        ans[i] = wont;
        if (wont > 1) continue;
        for (int j = i + i; j < max_n; j += i) {
            m[j][wont] = 1;
        }
    }
    int k = -1;
    for (int i = 2; i <= n + 1; ++i)
    {
        k = max(k, ans[i]);
    }
    cout << k << endl;
    for (int i = 2; i <= n + 1; ++i) cout << ans[i] << ' ' ;
    return 0;
}