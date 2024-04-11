#include <fstream>
#include <algorithm>
using namespace std;

const int Maxn = 2000;
const int Inf = Maxn * Maxn;

int n, m, k, quick[Maxn][Maxn], best = -1, bi, bj;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int x, y;
    fin >> n >> m;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) 
          quick[i][j] = Inf;
    fin >> k;
    while (k--) {
          fin >> x >> y; x--; y--;
          for (int i = 0; i < n; i++)
             for (int j = 0; j < m; j++) 
                quick[i][j] = min(quick[i][j], abs(x - i) + abs(y - j));
    }
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
          if (quick[i][j] > best) {
                          best = quick[i][j];
                          bi = i + 1; bj = j + 1;
          }
    fout << bi << " " << bj << endl;
    fin.close(); fout.close();
    return 0;
}