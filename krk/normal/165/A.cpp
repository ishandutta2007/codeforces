#include <cstdio>
using namespace std;

const int Maxn = 205;

int n;
int x[Maxn], y[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
    for (int i = 0; i < n; i++) {
        bool lef = false, rig = false, up = false, low = false;
        for (int j = 0; j < n; j++) {
            lef = lef || x[j] < x[i] && y[j] == y[i];
            rig = rig || x[i] < x[j] && y[j] == y[i];
            low = low || y[j] < y[i] && x[j] == x[i];
            up = up || y[i] < y[j] && x[j] == x[i];
        }
        res += lef && rig && up && low;
    }
    printf("%d\n", res);
    return 0;
}