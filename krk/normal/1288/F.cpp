/*
 * Algorithm : Simplex ( Linear Programming )
 * Author : Simon Lo
 * Note: Simplex algorithm on augmented matrix a of dimension (m+1)x(n+1)
 * returns 1 if feasible, 0 if not feasible, -1 if unbounded
 * returns solution in b[] in original var order, max(f) in ret
 * form: maximize sum_j(a_mj*x_j)-a_mn s.t. sum_j(a_ij*x_j)<=a_in
 * in standard form.
 * To convert into standard form:
 * 1. if exists equality constraint, then replace by both >= and <=
 * 2. if variable x doesn't have nonnegativity constraint, then replace by
 * difference of 2 variables like x1-x2, where x1>=0, x2>=0
 * 3. for a>=b constraints, convert to -a<=-b
 * note: watch out for -0.0 in the solution, algorithm may cycle
 * EPS = 1e-7 may give wrong answer, 1e-10 is better
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX 1007
#define INF 1000000007
 
// Caution: long double can give TLE
typedef long double ld;
typedef vector<ld> vd;
typedef vector<vd> vvd;

const ld EPS = 1e-10;


struct LPSolver {
  int m, n;
  vd B, N;
  vvd D;

  LPSolver(const vvd &A, const vd &b, const vd &c) :
    m(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, vd(n + 2)) {
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) D[i][j] = A[i][j];
    for (int i = 0; i < m; i++) { B[i] = n + i; D[i][n] = -1; D[i][n + 1] = b[i]; }
    for (int j = 0; j < n; j++) { N[j] = j; D[m][j] = -c[j]; }
    N[n] = -1; D[m + 1][n] = 1;
  }

  void Pivot(int r, int s) {
    ld inv = 1.0 / D[r][s];
    for (int i = 0; i < m + 2; i++) if (i != r)
        for (int j = 0; j < n + 2; j++) if (j != s)
            D[i][j] -= D[r][j] * D[i][s] * inv;
    for (int j = 0; j < n + 2; j++) if (j != s) D[r][j] *= inv;
    for (int i = 0; i < m + 2; i++) if (i != r) D[i][s] *= -inv;
    D[r][s] = inv;
    swap(B[r], N[s]);
  }

  bool Simplex(int phase) {
    int x = phase == 1 ? m + 1 : m;
    while (true) {
      int s = -1;
      for (int j = 0; j <= n; j++) {
        if (phase == 2 && N[j] == -1) continue;
        if (s == -1 || D[x][j] < D[x][s] || D[x][j] == D[x][s] && N[j] < N[s]) s = j;
      }
      if (D[x][s] > -EPS) return true;
      int r = -1;
      for (int i = 0; i < m; i++) {
        if (D[i][s] < EPS) continue;
        if (r == -1 || D[i][n + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||
                (D[i][n + 1] / D[i][s]) == (D[r][n + 1] / D[r][s]) && B[i] < B[r]) r = i;
      }
      if (r == -1) return false;
      Pivot(r, s);
    }
  }

  ld Solve(vd &x) {
    int r = 0;
    for (int i = 1; i < m; i++) if (D[i][n + 1] < D[r][n + 1]) r = i;
    if (D[r][n + 1] < -EPS) {
      Pivot(r, n);
      if (!Simplex(1) || D[m + 1][n + 1] < -EPS) return -numeric_limits<ld>::infinity();
      for (int i = 0; i < m; i++) if (B[i] == -1) {
          int s = -1;
          for (int j = 0; j <= n; j++)
            if (s == -1 || D[i][j] < D[i][s] || D[i][j] == D[i][s] && N[j] < N[s]) s = j;
          Pivot(i, s);
        }
    }
    if (!Simplex(2)) return numeric_limits<ld>::infinity();
    x = vd(n);
    for (int i = 0; i < m; i++) if (B[i] < n) x[B[i]] = D[i][n + 1];
    return D[m][n + 1];
  }
};

/* Equations are of the matrix form Ax<=b, and we want to maximize
the function c. We are given coeffs of A, b and c. In case of minimizing, 
we negate the coeffs of c and maximize it. Then the negative of returned 
'value' is the answer.
All the constraints should be in <= form. So we may need to negate the 
coeffs.
*/


int N1, N2, M, red, blue;
string S1, S2;
vector <int> E1[MAX], E2[MAX];
int n, m;
ld A[MAX][MAX], b[MAX], c[MAX]; 
int res[MAX];

int main()
{
    scanf("%d %d %d %d %d", &N1, &N2, &M, &red, &blue);
    n = 2 * M;
    for (int i = 0; i < n; i++) {
        c[i] = i < M? -red: -blue;
        A[m][i] = 1;
        b[m] = 1;
        m++;
    }
    cin >> S1;
    cin >> S2;
    for (int i = 0; i < M; i++) {
        int x, y; scanf("%d %d", &x, &y); x--; y--;
        E1[x].push_back(i);
        E2[y].push_back(i);
    }
    for (int i = 0; i < N1; i++) if (S1[i] == 'R' || S1[i] == 'B') {
        int add1 = M, add2 = 0;
        if (S1[i] == 'B') swap(add1, add2);
        for (int j = 0; j < E1[i].size(); j++) {
            int ind = E1[i][j];
            A[m][ind + add1] = 1;
            A[m][ind + add2] = -1;
        }
        b[m] = -1;
        m++;
    }
    for (int i = 0; i < N2; i++) if (S2[i] == 'R' || S2[i] == 'B') {
        int add1 = M, add2 = 0;
        if (S2[i] == 'B') swap(add1, add2);
        for (int j = 0; j < E2[i].size(); j++) {
            int ind = E2[i][j];
            A[m][ind + add1] = 1;
            A[m][ind + add2] = -1;
        }
        b[m] = -1;
        m++;
    }
    
    vvd vA(m);
    vd vb(b, b + m);
    vd vc(c, c + n);
    for (int i = 0; i < m; i++)
        vA[i] = vd(A[i], A[i] + n);
    LPSolver solver(vA, vb, vc);
    vd x;
    ld value = solver.Solve(x);
    if (value == numeric_limits<ld>::infinity() ||
        -value == numeric_limits<ld>::infinity()) {
        printf("-1\n");
        return 0;
    }
    cout << int(-value + EPS) << endl;
    for (int i = 0; i < M; i++)
        if (x[i] - x[i + M] > 0.5)
            printf("R");
        else if (x[i + M] - x[i] > 0.5)
            printf("B");
        else printf("U");
    printf("\n");
    return 0;
}