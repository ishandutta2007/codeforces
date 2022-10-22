#include <iostream>
using namespace std;

const int Maxn = 25;

int n, m;
char B[Maxn][Maxn];
int best = 0;

void Check(int i, int j, int i2, int j2)
{
     int curbest = 2 * (i2 - i + j2 - j + 2);
     if (curbest <= best) return;
     for (int i3 = i; i3 <= i2; i3++)
        for (int j3 = j; j3 <= j2; j3++)
           if (B[i3][j3] == '1') return;
     best = curbest;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) cin >> B[i][j];
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
          for (int i2 = i; i2 < n; i2++)
             for (int j2 = j; j2 < m; j2++)
                Check(i, j, i2, j2);
    cout << best << endl;
    return 0;
}