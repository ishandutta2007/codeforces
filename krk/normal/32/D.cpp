#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 301;

int n, m, k;
vector <pair <int, int> > cr[Maxn];
char B[Maxn][Maxn];

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) cin >> B[i][j];
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) if (B[i][j] == '*') {
           int to = min(min(i, j), min(n-i-1, m-j-1));
           for (int x = 1; x <= to; x++)
              if (B[i-x][j] == '*' && B[i+x][j] == '*' && 
                  B[i][j-x] == '*' && B[i][j+x] == '*')
                 cr[x].push_back(make_pair(i+1, j+1));
       }
    for (int x = 1; x < Maxn; x++)
       if (k > cr[x].size()) k -= cr[x].size();
       else {
            cout << cr[x][k-1].first     << " " << cr[x][k-1].second     << endl;
            cout << cr[x][k-1].first - x << " " << cr[x][k-1].second     << endl;
            cout << cr[x][k-1].first + x << " " << cr[x][k-1].second     << endl;
            cout << cr[x][k-1].first     << " " << cr[x][k-1].second - x << endl;
            cout << cr[x][k-1].first     << " " << cr[x][k-1].second + x << endl;
            return 0;
       }
    cout << "-1\n";
    return 0;
}