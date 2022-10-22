#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef long double ld;

const int Maxn = 2005;

int n;
ii p[Maxn];
bool tk[Maxn];
vector <int> seq;
ii lst0, lst1;
char str[Maxn];

ll Cross(const ii &a, const ii &b, const ii &c)
{
    ll ax = b.first - a.first, ay = b.second - a.second;
    ll bx = c.first - b.first, by = c.second - b.second;
    return ax * by - ay * bx;
}

void Take(int ind)
{
    seq.push_back(ind);
    tk[ind] = true;
    lst0 = lst1; lst1 = p[ind];
}

int main()
{
    scanf("%d", &n);
    int mn = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
        if (p[i] < p[mn]) mn = i;
    }
    lst1 = ii(p[mn].first + 1, -1000000001);
    Take(mn);
    scanf("%s", str);
    for (int i = 0; i < n - 2; i++)
        if (str[i] == 'L') {
            int mn = -1;
            for (int j = 1; j <= n; j++) if (!tk[j])
                if (mn == -1) mn = j;
                else if (Cross(lst1, p[mn], p[j]) < 0) mn = j;
            Take(mn);
        } else {
            int mx = -1;
            ld best;
            for (int j = 1; j <= n; j++) if (!tk[j])
                if (mx == -1) mx = j;
                else if (Cross(lst1, p[mx], p[j]) > 0) mx = j;
            Take(mx);
        }
    for (int j = 1; j <= n; j++) if (!tk[j])
        Take(j);
    for (int i = 0; i < seq.size(); i++)
        printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    return 0;
}