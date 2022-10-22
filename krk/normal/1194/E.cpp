#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef long long ll;

const int Maxn = 5005;
const int Maxb = 62;
const int Maxp = 85;

int n;
vector <iii> Y, X;
int p;
ll my[Maxn][Maxp];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int X1, Y1, X2, Y2; scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
        if (X1 > X2) swap(X1, X2);
        if (Y1 > Y2) swap(Y1, Y2);
        if (X1 == X2) X.push_back(iii(X1, ii(Y1, Y2)));
        else Y.push_back(iii(Y1, ii(X1, X2)));
    }
    if (X.size() > Y.size()) swap(X, Y);
    p = int(Y.size()) / Maxb + 1;
    for (int i = 0; i < X.size(); i++)
        for (int j = 0; j < Y.size(); j++)
            if (X[i].second.first <= Y[j].first && Y[j].first <= X[i].second.second &&
                Y[j].second.first <= X[i].first && X[i].first <= Y[j].second.second)
                my[i][j / Maxb] |= 1ll << ll(j % Maxb);
    for (int i = 0; i < X.size(); i++)
        for (int j = i + 1; j < X.size(); j++) {
            int got = 0;
            for (int k = 0; k < p; k++)
                got += __builtin_popcountll(my[i][k] & my[j][k]);
            res += ll(got) * (got - 1) / 2ll;
        }
    cout << res << endl;
    return 0;
}