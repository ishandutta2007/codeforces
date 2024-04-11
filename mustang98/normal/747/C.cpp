#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 105;

// ,     
int ser[max_n];
   int n, q;
int free(int t)
{
    int kolf = 0;
    for (int i = 0; i < n; i++)
    {
        if (ser[i] <= t) ser[i] = -1;
        if (ser[i] == -1) kolf++;
    }
    return kolf;
}

int main()
{
    //ifstream cin("input.txt");

    int t, k, d;
    for (int i = 0; i < max_n; i++)
    {
        ser[i] = -1;
    }
    cin >> n >> q;

    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d", &t, &k, &d);
        int kfr = free(t);
        if (kfr < k)
        {
            printf("%d\n", -1);
            continue;
        }
        int cur = 0;
        int sum = 0;
        while (k)
        {
            if (ser[cur] == -1)
            {
                ser[cur] = t + d;
                k--;
                sum += (cur + 1);
            }
            cur++;
        }
        printf("%d\n", sum);
    }

    return 0;
}