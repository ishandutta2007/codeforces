#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 150111, inf = 1000111222;

vector<int> v[max_n];
int in[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        v[i].PB(i);
        in[i] = i;
    }
    for (int i = 0; i + 1 < n; ++i) {
        int a , b;
        scanf("%d%d", &a, &b);
        --a, --b;
        int i1 = in[a];
        int i2 = in[b];
        if (v[i1].size() < v[i2].size()) {
            swap(i1, i2);
        }
        for (int j = 0; j < v[i2].size(); ++j) {
            int val = v[i2][j];
            in[val] = i1;
            v[i1].PB(val);
        }
        v[i2].clear();
    }
    int f = in[0];
    for (int a : v[f]) {
        printf("%d ", a + 1);
    }
    cout << endl;
    return 0;
}