#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011, inf = 1000111222;

int m[max_n][max_n];
int a, b, c;
int ab, ac, bc;

vector<int> fact(int a) {
    vector<int> ans;
    for (ll i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            ans.PB(i);
            ans.PB(a / i);
        }
    }
    return ans;
}

int n;
void ans() {
    printf("%d ", a);
    for (int i = 1; i < n; ++i) {
        if (m[0][i] % a) {
            exit(228);
        }
        printf("%d ", m[0][i] / a);
    }
    cout << endl;
    exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &m[i][j]);
        }
    }
    ab = m[0][1];
    ac = m[0][2];
    bc = m[1][2];
    vector<int> f = fact(ab);
    for (int cur : f) {
        a = cur;
        b = ab / a;
        if (ac % a) {
            continue;
        }
        c = ac / a;
        if (1LL * b * c == bc) {
            ans();
            return 0;
        }
    }
    exit(228);
    return 0;
}