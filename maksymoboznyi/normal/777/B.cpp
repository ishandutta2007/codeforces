#include <iostream>

using namespace std;

int k1[10], k2[10];

int main()
{
    int n;
    string a;
    string b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        k1[a[i] - '0']++;
    for (int i = 0; i < n; i++)
        k2[b[i] - '0']++;
    int ans1 = 0, add = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (k2[i] > k1[i])
            add += k2[i] - k1[i];
        else
        {
            int x = k1[i] - k2[i];
            if (add < x)
                ans1 += x - add, add = 0;
            else
                add -= x;
        }
    }
    cout << ans1 << endl;
    for (int i = 0; i < 10; i++)
        k1[i] = k2[i] = 0;
    for (int i = 0; i < n; i++)
        k1[a[i] - '0']++;
    for (int i = 0; i < n; i++)
        k2[b[i] - '0']++;
    int ans2 = 0;
    for (int i = 0; i < 10; i++) {
        int x = k1[i];
        for (int j = i + 1; j < 10; j++)
            while (x > 0 && k2[j] > 0)
                k2[j]--, x--, ans2++;
    }
    cout << ans2;
    return 0;
}