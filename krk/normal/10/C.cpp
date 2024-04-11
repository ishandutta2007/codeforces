#include <iostream>
using namespace std;

typedef long long ll;

const int Maxn = 10;

int n;
ll cnt[Maxn];
ll res;

int d(int x)
{
    return (x - 1) % 9 + 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cnt[d(i)]++;
    for (int A = 1; A < Maxn; A++)
       for (int B = 1; B < Maxn; B++)
          res += cnt[A] * cnt[B] * cnt[d(A * B)];
    for (int A = 1; A <= n; A++)
       res -= n / A;
    cout << res << endl;
    return 0;
}