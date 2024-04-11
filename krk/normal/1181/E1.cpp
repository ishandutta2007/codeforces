#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n;
int a[Maxn], b[Maxn], c[Maxn], d[Maxn];
vector <ii> X;
vector <int> V;

void Split(int a[], int b[], const vector <int> &V, int x, vector <int> &V1, vector <int> &V2)
{
    for (int i = 0; i < V.size(); i++) {
        int ind = V[i];
        if (b[ind] <= x) V1.push_back(ind);
        else V2.push_back(ind);
    }
}

bool Solve(const vector <int> &V)
{
    if (V.size() <= 1) return true;
    X.clear();
    for (int i = 0; i < V.size(); i++) {
        int ind = V[i];
        X.push_back(ii(a[ind], -1));
        X.push_back(ii(c[ind], 1));
    }
    sort(X.begin(), X.end());
    int st = 0;
    vector <int> V1, V2;
    for (int i = 0; i < X.size(); i++) {
        st += X[i].second;
        if (st == 0 && i + 1 < X.size()) {
            Split(a, c, V, X[i].first, V1, V2);
            return Solve(V1) && Solve(V2);
        }
    }
    X.clear();
    for (int i = 0; i < V.size(); i++) {
        int ind = V[i];
        X.push_back(ii(b[ind], -1));
        X.push_back(ii(d[ind], 1));
    }
    sort(X.begin(), X.end());
    st = 0;
    for (int i = 0; i < X.size(); i++) {
        st += X[i].second;
        if (st == 0 && i + 1 < X.size()) {
            Split(b, d, V, X[i].first, V1, V2);
            return Solve(V1) && Solve(V2);
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        c[i]--; d[i]--;
        V.push_back(i);
    }
    printf("%s\n", Solve(V)? "YES": "NO");
    return 0;
}