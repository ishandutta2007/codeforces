#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

vector <string> V;
int n;
ii a[Maxn];
char R[Maxn][Maxn];

void Solve(int x, int flag)
{
    int ind = x + 1;
    if (a[x].first == 0) return;
    if (ind == 1) {
        string s(n, '0');
        s[x] = '1';
        V.push_back(s);
        return;
    }
    if (a[x].first == ind) {
        string s(n, '0');
        int pnt = x;
        while (pnt >= 0 && a[pnt].first == ind) {
            a[pnt].first--; s[pnt] = '1';
            pnt--;
        }
        Solve(x - 1, x - 1 - pnt);
        if (V.size() == ind - 1) {
            for (int i = 0; i < ind - 2; i++)
                V[i][x] = '1';
            string s2(n, '0');
            s2[x] = '1';
            if (s == s2) {
                V[ind - 2][x] = '1';
                V.push_back(s);
            } else {
                if (flag != 1) swap(s, s2);
                V.push_back(s);
                V.push_back(s2);
            }
        } else {
            for (int i = 0; i < ind - 1; i++)
                V[i][x] = '1';
            V.push_back(s);
        }
    } else {
        Solve(x - 1, 0);
        if (V.size() == ind - 1) {
            string s2(n, '0');
            s2[x] = '1'; a[x].first--;
            V.push_back(s2);
        }
        for (int i = 0; i < a[x].first; i++)
            V[i][x] = '1';
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    Solve(n - 1, 0);
    for (int i = 0; i < V.size(); i++)
        for (int j = 0; j < n; j++)
            R[i][a[j].second] = V[i][j];
    printf("%d\n", int(V.size()));
    for (int i = 0; i < V.size(); i++) {
        R[i][n] = '\0';
        printf("%s\n", R[i]);
    }
    return 0;
}