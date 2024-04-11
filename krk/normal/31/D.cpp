#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int w, h, n;
vector <int> x1, y1, x2, y2;
vector <int> X1, Y1, X2, Y2;
vector <int> res;

int main()
{
    scanf("%d %d %d", &w, &h, &n);
    x1.resize(n); y1.resize(n); x2.resize(n); y2.resize(n);
    for (int i = 0; i < n; i++) scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
    X1.push_back(0); Y1.push_back(0); X2.push_back(w); Y2.push_back(h);
    while (X1.size() < n + 1)
          for (int i = 0; i < X1.size(); i++)
              for (int j = 0; j < n; j++)
                  if (x1[j] == x2[j] && 
                      X1[i] < x1[j] && x1[j] < X2[i] && Y1[i] == y1[j] && y2[j] == Y2[i] ||
                      y1[j] == y2[j] &&
                      Y1[i] < y1[j] && y1[j] < Y2[i] && X1[i] == x1[j] && X2[i] == x2[j]) {
                            X1.push_back(x1[j]); Y1.push_back(y1[j]); 
                            X2.push_back(X2[i]); Y2.push_back(Y2[i]);
                            X2[i] = x2[j]; Y2[i] = y2[j];
                  }
    res.resize(n + 1);
    for (int i = 0; i < res.size(); i++) res[i] = (X2[i] - X1[i]) * (Y2[i] - Y1[i]);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}