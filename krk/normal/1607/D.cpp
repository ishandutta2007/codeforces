#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
vector <int> red, blue;

bool Solve()
{
    int l = 1, r = n;
    sort(red.begin(), red.end());
    while (!red.empty()) {
        if (red.back() > r) return false;
        red.pop_back(); r--;
    }
    sort(blue.rbegin(), blue.rend());
    while (!blue.empty()) {
        if (blue.back() < l) return false;
        blue.pop_back(); l++;
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        red.clear();
        blue.clear();
        for (int i = 0; i < n; i++) {
            char ch; scanf(" %c", &ch);
            if (ch == 'B') blue.push_back(a[i]);
            else red.push_back(a[i]);
        }
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}