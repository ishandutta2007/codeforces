#include <bits/stdc++.h>

using namespace std;

const int max_n = 1e6 + 9, max_sqrt_z = 3765, max_z = max_sqrt_z * max_sqrt_z;

int m[max_z], p[max_n], sz[max_n], ANS;

int get_set(int a)
{
    return a == p[a] ? a : p[a] = get_set(p[a]);
}

int union_set(int a, int b)
{
    ANS--;
    int s1 = get_set(a);
    int s2 = get_set(b);
    if (sz[s1] < sz[s2])
    {
        swap(s1, s2);
    }
    sz[s1] += sz[s2];
    p[s2] = s1;
}

int main()
{
    int n, a, b, x, y, z;

    for (int i = 0; i < max_z; i++)
    {
        m[i] = -1;
    }

    scanf("%d", &n);
    ANS = n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        m[a] = i;
        p[i] = i;
        sz[i] = 1;
    }

    //   
    for (int a = 1; a <= max_sqrt_z; a++)
    {
        for (int b = a + 1; b <= max_sqrt_z; b += 2)
        {
            if (__gcd(a, b) > 1) continue;
            z = b * b + a * a;
            if (z > max_z) continue;
            y = 2 * a * b;
            x = b * b - a * a;
            if (m[x] != -1 && m[y] != -1)
            {
                if (get_set(m[x]) != get_set(m[y]))
                {
                    union_set(m[x], m[y]);
                }
            }
            if (m[x] != -1 && m[z] != -1)
            {
                if (get_set(m[x]) != get_set(m[z]))
                {
                    union_set(m[x], m[z]);
                }
            }
            if (m[z] != -1 && m[y] != -1)
            {
                if (get_set(m[z]) != get_set(m[y]))
                {
                    union_set(m[z], m[y]);
                }
            }
        }
    }
    printf("%d", ANS);
    return 0;
}