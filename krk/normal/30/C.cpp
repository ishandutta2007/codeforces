#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 1001;

struct target {
       int x, y, t;
       double p;
} T[Maxn];

int n;
double expect[Maxn], prob[Maxn][Maxn];

bool Less(const target &a, const target &b)
{
     return a.t < b.t;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
       cin >> T[i].x >> T[i].y >> T[i].t >> T[i].p;
    sort(T, T+n, Less);
    for (int i = 0; i < n; i++) {
        int best = -1;
        for (int j = 0; j < i; j++) 
           if ((long long) (T[i].t - T[j].t) * (T[i].t - T[j].t) >= 
                           (T[i].x - T[j].x) * (T[i].x - T[j].x) + 
                           (T[i].y - T[j].y) * (T[i].y - T[j].y) &&
               (best == -1 || expect[j] > expect[best])) best = j;
        if (best == -1) { prob[i][1] = T[i].p; prob[i][0] = 1 - T[i].p; }
        else for (int j = 0; j <= n; j++) {
                prob[i][j] = prob[best][j] * (1 - T[i].p);
                if (j) prob[i][j] += prob[best][j-1] * T[i].p;
             }
        for (int j = 1; j <= n; j++) expect[i] += j * prob[i][j];
    }
    double best = -1;
    for (int i = 0; i < n; i++) if (expect[i] > best) best = expect[i];
    cout << fixed << setprecision(10) << best << endl;
    return 0;
}