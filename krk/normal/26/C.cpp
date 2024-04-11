#include <iostream>
using namespace std;

const int Maxn = 100;

int n, m, a, b, c;
int B[Maxn][Maxn];

void makePar(int ro, int co)
{
     if (ro >= n-1) return;
     if (co >= m-1) { makePar(ro + 2, 0); return; }
     if (B[ro][co]) { makePar(ro, co + 2); return; }
     int ch = 1;
     if (c) {
            while (ro && (B[ro-1][co] == ch || B[ro-1][co+1] == ch) ||
                   co && (B[ro][co-1] == ch || B[ro+1][co-1] == ch)) ch++;
            B[ro][co] = B[ro+1][co] = B[ro][co+1] = B[ro+1][co+1] = ch;
            c--;
            makePar(ro, co + 2);
     } else if (a) {
            while (ro && (B[ro-1][co] == ch || B[ro-1][co+1] == ch) ||
                   co && B[ro][co-1] == ch) ch++; 
            B[ro][co] = B[ro][co+1] = ch; a--;
            ch = 1; ro++;
            while (ro && (B[ro-1][co] == ch || B[ro-1][co+1] == ch) ||
                   co && B[ro][co-1] == ch) ch++; 
            B[ro][co] = B[ro][co+1] = ch; a--;
            makePar(ro - 1, co + 2);
     } else if (b) {
            while (ro && B[ro-1][co] == ch ||
                   co && (B[ro][co-1] == ch || B[ro+1][co-1] == ch)) ch++;
            B[ro][co] = B[ro+1][co] = ch; b--;
            ch = 1; co++;
            while (ro && B[ro-1][co] == ch ||
                   co && (B[ro][co-1] == ch || B[ro+1][co-1] == ch)) ch++;
            B[ro][co] = B[ro+1][co] = ch; b--;
            makePar(ro, co + 1);
     }
}

int main()
{
    cin >> n >> m >> a >> b >> c;
    if (n % 2 && m % 2) { cout << "IMPOSSIBLE\n"; return 0; }
    if (m % 2) {
          if (b < n/2) { cout << "IMPOSSIBLE\n"; return 0; }
          b -= n/2;
    } else if (n % 2) {
           if (a < m/2) { cout << "IMPOSSIBLE\n"; return 0; }
           a -= m/2;
    } else {
           if (a % 2) a--;
           if (b % 2) b--;
    }
    if (2 * a + 2 * b + 4 * c < (n - n % 2) * (m - m % 2)) { cout << "IMPOSSIBLE\n"; return 0; }
    makePar(0, 0);
    if (n % 2)
       for (int co = 0; co < m; co += 2) {
           int ch = 1;
           while (n > 1 && (B[n-2][co] == ch || B[n-2][co+1] == ch) ||
                  co && B[n-1][co-1] == ch) ch++; 
           B[n-1][co] = B[n-1][co+1] = ch;
       }
    else if (m % 2) {
         for (int ro = 0; ro < n; ro += 2) {
             int ch = 1;
             while (ro && B[ro-1][m-1] == ch ||
                    m > 1 && (B[ro][m-2] == ch || B[ro+1][m-2] == ch)) ch++;
             B[ro][m-1] = B[ro+1][m-1] = ch;
         }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << char('a' + B[i][j] - 1);
        cout << endl;
    }
    return 0;
}