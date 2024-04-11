#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int Maxm = 55;

int m, n;
char B[Maxm][Maxm];

struct group {
       char col;
       int xmin, xmax, ymin, ymax;
       group(int y = 0, int x = 0) {
                 col = B[y][x];
                 xmin = xmax = x;
                 ymin = ymax = y;
       }
       void Add(int y, int x) {
            xmax = max(xmax, x);
            ymax = max(ymax, y);
       }
};

vector <group> G;
int ingroup[Maxm][Maxm];

bool canGetGroup(int &b, int d, int c)
{
     int y, x;
     switch (d) {
            case 0: y = G[b].ymin - 1; break;
            case 1: x = G[b].xmax + 1; break;
            case 2: y = G[b].ymax + 1; break;
            case 3: x = G[b].xmin - 1; break;
     }
     switch (c) {
            case 0: y = G[b].ymin; break;
            case 1: x = G[b].xmax; break;
            case 2: y = G[b].ymax; break;
            case 3: x = G[b].xmin; break;
     }
     if (B[y][x] == '0') return false;
     b = ingroup[y][x];
     return true;
}

int main()
{
    fill((char*)B, (char*)B + Maxm * Maxm, '0');
    cin >> m >> n; cin.ignore();
    for (int i = 1; i <= m; i++) {
        int j = 1;
        while (cin.peek() != '\n') {
              cin >> B[i][j];
              if (B[i][j] != '0')
                 if (B[i][j] == B[i - 1][j]) {
                             ingroup[i][j] = ingroup[i - 1][j];
                             G[ingroup[i][j]].Add(i, j);
                 } else if (B[i][j] == B[i][j - 1]) {
                        ingroup[i][j] = ingroup[i][j - 1];
                        G[ingroup[i][j]].Add(i, j);
                 } else {
                        ingroup[i][j] = G.size();
                        G.push_back(group(i, j));
                 }
              j++;
        }
        cin.ignore();
    }
    int b = ingroup[1][1];
    int c = 0, d = 1;
    while (n--)
        if (!canGetGroup(b, d, c))
           if ((c + 1) % 4 == d) c = (d + 1) % 4;
           else swap(c, d);
    cout << G[b].col << endl;
    return 0;
}