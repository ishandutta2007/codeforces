#include <fstream>
#include <algorithm>
using namespace std;

int t, k, n, m;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> t >> k;
    if (k == 1)
          while (t--) {
                fin >> n >> m;
                if (n % 2 && m % 2) fout << "-\n";
                else fout << "+\n";
          }
    else while (t--) {
            fin >> n >> m;
            if (n < m) swap(n, m);
            if (m % (k+1) == 0) fout << "+\n";
            else if ((m / (k + 1) % 2 == 1) ^ ((n - m) % 2 == 1)) fout << "+\n";
                 else fout << "-\n";
    }
    fin.close(); fout.close();
    return 0;
}