#include <fstream>
#include <string>
using namespace std;

const int Maxn = 31;

int n, m, k;
string W[Maxn][Maxn];
ifstream fin("input.txt");
ofstream fout("output.txt");

void Insert(int x, int y, const string &s)
{
     for (int i = x; i <= n; i++) {
         int j;
         if (i == x) j = y;
         else j = 1;
         for (; j <= m; j++)
            if (W[i][j] == "") {
                        W[i][j] = s; break;
            }
         if (j <= m) break;
     }
}

void Delete(const string &s)
{
     int i;
     for (i = 1; i <= n; i++) {
         int j;
         for (j = 1; j <= m; j++)
            if (W[i][j] == s) {
                        W[i][j] = "";
                        fout << i << " " << j << endl;
                        break;
            }
         if (j <= m) break;
     }
     if (i > n) fout << "-1 -1\n";
}

int main()
{
    int act, x, y;
    string id;
    fin >> n >> m >> k;
    while (k--) {
          fin >> act;
          if (act > 0) { 
                  fin >> x >> y >> id;
                  Insert(x, y, id);
          } else {
                 fin >> id;
                 Delete(id);
          }
    }
    fin.close(); fout.close();
    return 0;
}