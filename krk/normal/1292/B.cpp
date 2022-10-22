#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <ll> X, Y;
ll ax, ay, bx, by;
ll myX, myY, tim;
int res;

bool checkForw(int a, int b)
{
    ll lft = tim - abs(myX - X[a]) - abs(myY - Y[a]);
    if (lft < 0) return false;
    for (int i = a + 1; i <= b; i++) {
        lft = lft - abs(X[i - 1] - X[i]) - abs(Y[i - 1] - Y[i]);
        if (lft < 0) return false;
    }
    return true;
}

bool checkBackw(int a, int b)
{
    ll lft = tim - abs(myX - X[b]) - abs(myY - Y[b]);
    if (lft < 0) return false;
    for (int i = b - 1; i >= a; i--) {
        lft = lft - abs(X[i + 1] - X[i]) - abs(Y[i + 1] - Y[i]);
        if (lft < 0) return false;
    }
    return true;
}

int main()
{
    ll x, y; scanf("%I64d %I64d", &x, &y);
    X.push_back(x); Y.push_back(y);
    scanf("%I64d %I64d", &ax, &ay);
    scanf("%I64d %I64d", &bx, &by);
    scanf("%I64d %I64d %I64d", &myX, &myY, &tim);
    while (X.back() <= myX || Y.back() <= myY || X.back() - myX + Y.back() - myY <= tim) {
        ll nX = X.back() * ax + bx;
        ll nY = Y.back() * ay + by;
        X.push_back(nX); Y.push_back(nY);
    }
    for (int i = 0; i < X.size(); i++)
        for (int j = i; j < X.size(); j++)
            if (checkForw(i, j) || checkBackw(i, j))
                res = max(res, j - i + 1);
    printf("%d\n", res);
    return 0;
}