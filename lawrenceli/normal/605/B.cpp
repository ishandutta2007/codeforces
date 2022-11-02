#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ios>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;

const int maxn = 100100;

int n, m;
piii ar[maxn];
int ea[maxn], eb[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> ar[i].A >> ar[i].B.A;
        ar[i].B.B = i;
        ar[i].B.A ^= 1;
    }

    sort(ar, ar + m);

    int cnt = 0, num = 1;
    int la = 3, lb = 2;
    for (int i = 0; i < m; i++) {
        int ind = ar[i].B.B;
        if (ar[i].B.A == 1) {
            cnt++;
            if (cnt > ll(num - 1) * (num - 2) / 2) {
                cout << "-1\n";
                return 0;
            } else {
                ea[ind] = la, eb[ind] = lb;
                if (lb + 1 == la) la++, lb = 2;
                else lb++;
            }
        } else {
            ea[ind] = 1, eb[ind] = num + 1;
            num++;
        }
    }

    for (int i = 0; i < m; i++)
        cout << ea[i] << ' ' << eb[i] << '\n';
}