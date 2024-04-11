#include <iostream>
#include <cstdio>
#include <cmath>


using namespace std;

const int N = 200001, inf = 400001;

bool u[N], d[N];
    int uu[N], ud[N], dd[N], du[N];

int main()
{
    int n, m, sum, pos, r, t1, t2;
    char c;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        scanf("%c", &c);
        while (c != '.' && c != 'X')
            scanf("%c", &c);
        u[i] = (c == 'X');
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%c", &c);
        while (c != '.' && c != 'X')
            scanf("%c", &c);
        d[i] = (c == 'X');
    }
    r = sqrt(n);
    /* u */{
    for (int i = 0; i + r < n; ++i)
    {
        pos = 0;
        uu[i] = 0;
        for (int j = i; j < i + r; ++j)
        {
            if (u[j + 1] && d[j + 1])
            {
                uu[i] = inf;
                break;
            }
            if (pos == 0)
            {
                if (!u[j + 1])
                    uu[i]++;
                else
                {
                    if (d[j])
                    {
                        uu[i] = inf;
                        break;
                    }
                    uu[i] += 2;
                    pos = 1;
                }
            }
            else
            {
                if (!d[j + 1])
                    uu[i]++;
                else
                {
                    if (u[j])
                    {
                        uu[i] = inf;
                        break;
                    }
                    uu[i] += 2;
                    pos = 0;
                }
            }
        }
        if (uu[i] == inf)
            ud[i] = inf;
        else if (pos == 1)
        {
            ud[i] = uu[i];
            uu[i]++;
        }
        else
            ud[i] = uu[i] + 1;
        if (d[i + r])
            ud[i] = inf;
        if (u[i + r])
            uu[i] = inf;
    }
    /* */}
    /* d */{
    for (int i = 0; i + r < n; ++i)
    {
        pos = 1;
        dd[i] = 0;
        for (int j = i; j < i + r; ++j)
        {
            if (u[j + 1] && d[j + 1])
            {
                dd[i] = inf;
                break;
            }
            if (pos == 0)
            {
                if (!u[j + 1])
                    dd[i]++;
                else
                {
                    if (d[j])
                    {
                        dd[i] = inf;
                        break;
                    }
                    dd[i] += 2;
                    pos = 1;
                }
            }
            else
            {
                if (!d[j + 1])
                    dd[i]++;
                else
                {
                    if (u[j])
                    {
                        dd[i] = inf;
                        break;
                    }
                    dd[i] += 2;
                    pos = 0;
                }
            }
        }
        if (dd[i] == inf)
            du[i] = inf;
        else if (pos == 0)
        {
            du[i] = dd[i];
            dd[i]++;
        }
        else
            du[i] = dd[i] + 1;
        if (d[i + r])
            dd[i] = inf;
        if (u[i + r])
            du[i] = inf;
    }
    /* */}

    for (int x = 0; x < m; ++x)
    {
        scanf("%d %d", &t1, &t2);
        if ((t1 - 1) % n > (t2 - 1) % n)
            swap(t1, t2);
        pos = (t1 - 1) / n;
        sum = 0;
        for (int i = (t1 - 1) % n; i + r <= (t2 - 1) % n; i += r)
        {
            if (pos == 0)
            {
                if (ud[i] < uu[i])
                    pos = 1;
                sum += min(ud[i], uu[i]);
            }
            else
            {
                if (dd[i] > du[i])
                    pos = 0;
                sum += min(dd[i], du[i]);
            }
            if (sum >= inf)
                break;
        }
        if (sum >= inf)
            printf("-1");
        else
        {
            for (int i = (((t2 - 1) % n - (t1 - 1) % n) / r) * r + (t1 - 1) % n; i < (t2 - 1) % n; ++i)
            {
                if (u[i + 1] && d[i + 1])
                {
                    printf("-1");
                    sum = inf;
                    break;
                }
                if (pos == 0)
                {
                    if (!u[i + 1])
                        sum++;
                    else
                    {
                        if (d[i])
                        {
                            printf("-1");
                            sum = inf;
                            break;
                        }
                        sum += 2;
                        pos = 1;
                    }
                }
                else
                {
                    if (!d[i + 1])
                        sum++;
                    else
                    {
                        if (u[i])
                        {
                            printf("-1");
                            sum = inf;
                            break;
                        }
                        sum += 2;
                        pos = 0;
                    }
                }
            }
            if (sum < inf)
            {
                if (pos != (t2 - 1) / n)
                    printf("%d", sum + 1);
                else
                    printf("%d", sum);
            }
        }
        printf("\n");
    }
    return 0;
}