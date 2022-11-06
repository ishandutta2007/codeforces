#include <iostream>
#define N  100005
using namespace std;
int a[N];
int n;
int main()
{
    cin >> n;
    int x;
    for (int i = 0;i < N; i++)
        a[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int j = 2; j * j <= x; j++)
            if (x%j == 0)
                if (x / j == j)
                    a[j]++;
                else
                {
                    a[j]++;
                    a[x / j]++;
                }
        a[x]++;
    }

    int ma = 1;
    //cout << a[2];
    for (int i = 2; i < N; i++)
        ma = max(ma, a[i]);
    cout << ma;
    return 0;
}