#include <iostream>
#include <algorithm>
using namespace std;

const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int x[3], y[3];
bool stop;

bool Good()
{
     int dist[3];
     dist[0] = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
     dist[1] = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
     dist[2] = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
     sort(dist, dist + 3);
     if (dist[0] == 0) return false;
     return dist[0] + dist[1] == dist[2];
}

int main()
{
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    if (Good()) cout << "RIGHT\n";
    else {
         for (int i = 0; i < 3 && !stop; i++)
             for (int j = 0; j < Maxd && !stop; j++) {
                 x[i] += dy[j]; y[i] += dx[j];
                 if (Good()) stop = true;
                 x[i] -= dy[j]; y[i] -= dx[j];
             }
         if (stop) cout << "ALMOST\n";
         else cout << "NEITHER\n";
    }
    return 0;
}