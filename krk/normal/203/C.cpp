#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, d;
int a, b;

struct pos {
    int x, y;
    int ind;
    pos(int x = 0, int y = 0, int ind = 0): x(x), y(y), ind(ind) {}
    bool operator <(const pos &p) const {
        return a * x + b * y < a * p.x + b * p.y;
    }
};

vector <pos> V;
int res;

int main()
{
    scanf("%d %d", &n, &d);
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        V.push_back(pos(x, y, i));
    }
    sort(V.begin(), V.end());
    while (res < V.size() && a * V[res].x + b * V[res].y <= d) {
        d -= a * V[res].x + b * V[res].y;
        res++;
    }
    printf("%d\n", res);
    for (int i = 0; i < res; i++) {
        if (i) printf(" ");
        printf("%d", V[i].ind);
    }
    printf("\n");
    return 0;
}