#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 105;
const int Maxb = 11;
 
int n, m, k;
char B[Maxn][Maxn];
bool wasG, wasR;
int zers, ones;
int has[Maxb];
 
void First()
{
    printf("First\n");
}
 
void Second()
{
    printf("Second\n");
}
 
void Draw()
{
    printf("Draw\n");
}
 
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", B[i]);
        vector <int> V;
        for (int j = 0; j < m; j++)
            if (B[i][j] == 'G' || B[i][j] == 'R')
                V.push_back(j);
        if ((V.size() == 1 || V.size() == 2 && B[i][V[0]] == B[i][V[1]]) &&
            V.size() < m)
            if (B[i][V[0]] == 'G') wasG = true;
            else wasR = true;
        else if (V.size() == 2 && B[i][V[0]] != B[i][V[1]]) {
            int cur = V[1] - V[0] - 1;
            for (int i = 0; i < Maxb; i++)
                if (cur & 1 << i) has[i]++;
        }
    }
    if (wasG && wasR) { Draw(); return 0; }
    if (wasG) { First(); return 0; }
    if (wasR) { Second(); return 0; }
    for (int i = 0; i < Maxb; i++)
        if (has[i] % (k + 1)) { First(); return 0; }
    Second();
    return 0;
}