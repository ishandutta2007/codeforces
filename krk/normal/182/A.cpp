#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const double eps = 1e-8;
const int Inf = 1000000000;

int a, b;
int Ax, Ay, Bx, By;
int n;
int X1[Maxn], Y1[Maxn], X2[Maxn], Y2[Maxn];
int dist[Maxn];
queue <int> Q;

double Dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double Dot(double ax, double ay, double bx, double by) { return ax * bx + ay * by; }

double Dist(double X1, double Y1, double X2, double Y2, double Ax, double Ay)
{
    double ax = X2 - X1, ay = Y2 - Y1;
    double bx = Ax - X1, by = Ay - Y1;
    if (Dot(ax, ay, bx, by) < 0) return Dist(X1, Y1, Ax, Ay);
    if (Dot(-ax, -ay, Ax - X2, Ay - Y2) < 0) return Dist(X2, Y2, Ax, Ay);
    return abs(ax * by - ay * bx) / Dist(X1, Y1, X2, Y2);
}

bool hasEdge(int i, int j)
{
    double dist;
    if (X1[i] == X2[i] && X1[j] == X2[j]) {
        if (Y1[i] > Y1[j]) swap(i, j);
        if (Y1[j] <= Y2[i]) dist = abs(X1[j] - X1[i]);
        else dist = Dist(X2[i], Y2[i], X1[j], Y1[j]);
    } else if (Y1[i] == Y2[i] && Y1[j] == Y2[j]) {
        if (X1[i] > X1[j]) swap(i, j);
        if (X1[j] <= X2[i]) dist = abs(Y1[j] - Y1[i]);
        else dist = Dist(X2[i], Y2[i], X1[j], Y1[j]);
    } else {
        if (Y1[j] == Y2[j]) swap(i, j);
        if (X1[i] <= X1[j] && X1[j] <= X2[i]) dist = min(abs(Y1[j] - Y1[i]), abs(Y2[j] - Y1[i]));
        else if (Y1[j] <= Y1[i] && Y1[i] <= Y2[j]) dist = min(abs(X1[j] - X1[i]), abs(X1[j] - X2[i]));
        else if (X1[j] < X1[i]) dist = min(Dist(X1[j], Y1[j], X1[i], Y1[i]), Dist(X2[j], Y2[j], X1[i], Y1[i]));
        else dist = min(Dist(X1[j], Y1[j], X2[i], Y2[i]), Dist(X2[j], Y2[j], X2[i], Y2[i]));
    }
    return dist <= a + eps;
}

int main()
{
    scanf("%d %d", &a, &b);
    scanf("%d %d %d %d", &Ax, &Ay, &Bx, &By);
    if (Dist(Ax, Ay, Bx, By) <= a + eps) { printf("%.10lf\n", Dist(Ax, Ay, Bx, By)); return 0; }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
        if (X1[i] > X2[i] || X1[i] == X2[i] && Y1[i] > Y2[i]) {
            swap(X1[i], X2[i]); swap(Y1[i], Y2[i]);
        }
        if (Dist(X1[i], Y1[i], X2[i], Y2[i], Ax, Ay) <= a + eps) {
            dist[i] = 1;
            Q.push(i);
        } else dist[i] = Inf;
    }
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < n; i++) if (hasEdge(v, i) && dist[v] + 1 < dist[i]) {
            dist[i] = dist[v] + 1;
            Q.push(i);
        }
    }
    double res = Inf;
    for (int i = 0; i < n; i++)
        if (dist[i] < Inf && Dist(X1[i], Y1[i], X2[i], Y2[i], Bx, By) <= a + eps)
            res = min(res, dist[i] * (a + b) + Dist(X1[i], Y1[i], X2[i], Y2[i], Bx, By));
    if (fabs(res - Inf) < eps) printf("-1\n");
    else printf("%.10lf\n", res);
    return 0;
}