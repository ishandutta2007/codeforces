#include <bits/stdc++.h>
using namespace std;

int n, k, m, t;
vector <bool> V;

int Find(const vector <bool> &V)
{
    for (int i = 0; i < V.size(); i++)
        if (V[i]) return i;
    return -1;
}

int main()
{
    scanf("%d %d %d %d", &n, &k, &m, &t);
    for (int i = 0; i < n; i++)
        V.push_back(false);
    k--; V[k] = true;
    while (t--) {
        int a, b; scanf("%d %d", &a, &b);
        if (a == 1) V.insert(V.begin() + b - 1, false);
        else {
            vector <bool> A, B;
            for (int i = 0; i < b; i++)
                A.push_back(V[i]);
            for (int i = b; i < V.size(); i++)
                B.push_back(V[i]);
            if (Find(A) == -1) V = B;
            else V = A;
        }
        printf("%d %d\n", int(V.size()), Find(V) + 1);
    }
    return 0;
}