#include <iostream>
#include <deque>
#include <list>
#define N 1200000

using namespace std;

int64_t p = 42, q = 1, a[N], pa[N];

deque<int> x;
inline bool test_pal(int n)
{
    x.clear();
    while (n)
    {
        x.push_back(n % 10);
        n /= 10;
    }
    while (!x.empty())
    {
        if (x.front() != x.back())
            return 0;
        x.pop_front();
        if (!x.empty())
            x.pop_back();
    }
    return 1;
}

int main()
{
    cin >> p >> q;
    for (int i = 2; i * i < N; ++i) if (a[i] == 0)
        for (int j = i * i; j < N; j += i)
            a[j] = 1;
    int bst = 0;
    a[0] = -1;
    for (int i = 1; i < N; ++i)
    {
        a[i] = !a[i] + a[i - 1], pa[i] = pa[i - 1] + test_pal(i);
        if (a[i] * q <= pa[i] * p)
            bst = i;
    }
//    if (bst <= N / 2)
        cout << bst;
//    else
//        cout << "Palindromic tree is better than splay tree";
    return 0;
}