#include <iostream>
#include <algorithm>
using namespace std;

int a, b, x1, y1, x2, y2;
int X1, Y1, X2, Y2;
int res1, res2;

int Div(int x, int d)
{
    int res = x / d;
    if (x < d * res) res--;
    return res;
}

int main()
{
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    X1 = x1 - y1, Y1 = x1 + y1, X2 = x2 - y2; Y2 = x2 + y2;
    int p1 = Div(X1, 2 * b), p2 = Div(X2, 2 * b);
    res1 = abs(p1 - p2);
    p1 = Div(Y1, 2 * a), p2 = Div(Y2, 2 * a);
    res2 = abs(p1 - p2);
    cout << max(res1, res2) << endl;
    return 0;
}