#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 1001, Inf = 100000000;

int best[Maxn][Maxn];
pair <int, int> p[Maxn][Maxn];
string a, b;

int getBest(int i, int j)
{
    if (i < 0 || j < 0) return Inf;
    if (best[i][j] == -1) {
                   int tmp;
                   best[i][j] = getBest(i - 1, j) + 1;
                   p[i][j] = make_pair(i - 1, j);
                   tmp = getBest(i, j - 1) + 1;
                   if (tmp < best[i][j]) {
                           best[i][j] = tmp;
                           p[i][j] = make_pair(i, j - 1);
                   }
                   if (i && j) {
                           tmp = getBest(i - 1, j - 1);
                           if (a[i - 1] != b[j - 1]) tmp++;
                           if (tmp < best[i][j]) {
                                   best[i][j] = tmp;
                                   p[i][j] = make_pair(i - 1, j - 1);
                           }
                   }
    }
    return best[i][j];
}

void printPath(int i, int j)
{
     if (i == 0 && j == 0) return;
     printPath(p[i][j].first, p[i][j].second);
     if (p[i][j].first == i - 1 && p[i][j].second == j) 
        cout << "DELETE " << j + 1 << endl;
     else if (p[i][j].first == i && p[i][j].second == j - 1)
        cout << "INSERT " << j << " " << b[j - 1] << endl;
     else if (a[i - 1] != b[j - 1]) cout << "REPLACE " << j << " " << b[j - 1] << endl;
}

int main()
{
    cin >> a >> b;
    for (int i = 0; i <= a.length(); i++)
       for (int j = 0; j <= b.length(); j++) best[i][j] = -1;
    best[0][0] = 0;
    cout << getBest(a.length(), b.length()) << endl;
    printPath(a.length(), b.length());
    return 0;
}