#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int Maxn = 55;

int n, m;
int c[Maxn][Maxn];
int cols[Maxn], rows[Maxn];
int scols[Maxn], srows[Maxn];
int A, B, C;
int res;

bool Good(int a, int b, int c)
{
    return a == A && b == B && c == C ||
           a == A && b == C && c == B ||
           a == B && b == A && c == C ||
           a == B && b == C && c == A ||
           a == C && b == A && c == B ||
           a == C && b == B && c == A;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) cin >> c[i][j];
    cin >> A >> B >> C;
       
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) rows[i] += c[i][j];
    for (int j = 0; j < m; j++)
       for (int i = 0; i < n; i++) cols[j] += c[i][j];
       
    for (int i = 0; i < n; i++) {
        srows[i] = rows[i];
        if (i) srows[i] += srows[i - 1];
    }
    for (int j = 0; j < m; j++) {
        scols[j] = cols[j];
        if (j) scols[j] += scols[j - 1];
    }
    
    for (int i1 = 0; i1 < n; i1++)
       for (int i2 = i1 + 1; i2 + 1 < n; i2++)
          res += Good(srows[i1], srows[i2] - srows[i1], srows[n - 1] - srows[i2]);
          
    for (int j1 = 0; j1 < m; j1++)
       for (int j2 = j1 + 1; j2 + 1 < m; j2++)
          res += Good(scols[j1], scols[j2] - scols[j1], scols[m - 1] - scols[j2]);
          
    cout << res << endl;
    return 0;
}