#include <iostream>
#define n1 2 * n + 1
#define n2 2 * n + 2
#define N 10000
#define sabs(n) n < 0? -n:n
#define abs(n) (sabs((n)))

using namespace std;

int an[N], l[N], w[N], am;

void sol(int n)
{
    if (n >= am)
        return;
    sol(n1);
    sol(n2);
    an[n] = abs(l[n1] + w[n1] - l[n2] - w[n2]) + an[n1] + an[n2];
    l[n] = max(l[n1] + w[n1], l[n2] + w[n2]);
}

int main()
{
    int n;
    cin >> n;
    am = (1 << (n + 1)) - 2;
    for (int i = 0; i < am; ++i)
        cin >> w[i + 1];
    sol(0);
    cout << an[0];
    return 0;
}