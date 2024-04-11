#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
int mx[Maxn];
vector <int> my[Maxn];
ll g = 1;

int main()
{
    for (int i = 2; i < Maxn; i++) if (mx[i] == 0)
        for (int j = i; j < Maxn; j += i) mx[j] = i;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        while (a[i] > 1) {
            int cur = mx[a[i]], mycnt = 0;
            while (mx[a[i]] == cur) {
                a[i] /= cur; mycnt++;
            }
            my[cur].push_back(mycnt);
        }
    }
    for (int i = 2; i < Maxn; i++) if (mx[i] == i) {
        sort(my[i].begin(), my[i].end());
        int ans = 0;
        if (my[i].size() == n) ans = my[i][1];
        else if (my[i].size() == n - 1) ans = my[i][0];
        while (ans--) g *= i;
    }
    cout << g << endl;
    return 0;
}