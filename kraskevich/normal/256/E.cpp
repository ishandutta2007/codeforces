#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <stdlib.h>
#include <cmath>
#include <ctype.h>

using namespace std;

struct fastInOut
{
    int nextInt()
    {
        char c = 'x';
        bool minus = false;
        int res = 0;
        while (!isdigit(c) && c != '+' && c != '-')
            c = getc(stdin);
        if (c == '-')
            minus = true;
        if (c == '-' || c == '+')
            c = getc(stdin);
        while(isdigit(c))
        {
            res = res * 10 + (int)c  -(int)'0';
            c = getc(stdin);
        }
        if (minus)
            res = -res;
        return res;
    }

    long long nextLongLong()
    {
        char c = 'x';
        bool minus = false;
        long long res = 0;
        while (!isdigit(c) && c != '+' && c != '-')
            c = getc(stdin);
        if (c == '-')
            minus = true;
        if (c == '-' || c == '+')
            c = getc(stdin);
        while(isdigit(c))
        {
            res = res * 10 + (int)c  -(int)'0';
            c = getc(stdin);
        }
        if (minus)
            res = -res;
        return res;
    }

    void printInt(int n)
    {
        if (n == 0)
        {
            putc('0', stdout);
            return;
        }
        if (n < 0)
        {
            putc('-', stdout);
            n = -n;
        }
        char buf[21];
        int size = 0;
        while (n > 0)
        {
            buf[size++] = n % 10 + '0';
            n /= 10;
        }
        for (int i = size - 1; i >= 0; --i)
            putc(buf[i], stdout);
    }

    void printLongLong(long long n)
    {
        if (n == 0)
        {
            putc('0', stdout);
            return;
        }
        if (n < 0)
        {
            putc('-', stdout);
            n = -n;
        }
        char buf[25];
        int size = 0;
        while (n > 0)
        {
            buf[size++] = n % 10 + '0';
            n /= 10;
        }
        for (int i = size - 1; i >= 0; --i)
            putc(buf[i], stdout);

    }

    void printLn()
    {
        puts("");
    }

    void printChar(char c)
    {
        putc(c, stdout);
    }
};


const int N = 100 * 1000;
const long long mod = 777777777;
long long dp[4 * N + 10][3][3];
int good[3][3];

void build(int pos, int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                dp[pos][i][j] = 0;
        for (int i = 0; i < 3; ++i)
            dp[pos][i][i] = 1;
        return;
    }

    int childLeft = 2 * pos + 1, childRight = 2 * pos + 2;
    int m = (l + r) / 2;

    build(childLeft, l, m);
    build(childRight, m + 1, r);

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            dp[pos][i][j] = 0;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int bodl = 0; bodl < 3; ++bodl)
                for (int bodr = 0; bodr < 3; ++bodr)
                    if (good[bodl][bodr])
                    {
                        dp[pos][i][j] += dp[childLeft][i][bodl] * dp[childRight][bodr][j];
                        dp[pos][i][j] %= mod;
                    }
}



void update(int pos, int l, int r, int where, int newVal)
{
    if (l == where && r == where)
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                dp[pos][i][j] = 0;
        for(int i = 0; i < 3; ++i)
            if (i == newVal || newVal == -1)
                dp[pos][i][i] = 1;
        return;
    }

    int childLeft = 2 * pos + 1, childRight = 2 * pos + 2;
    int m = (l + r) / 2;

    if (where <= m)
        update(childLeft, l, m, where, newVal);
    else
        update(childRight, m + 1, r, where, newVal);

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            dp[pos][i][j] = 0;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int bodl = 0; bodl < 3; ++bodl)
                for (int bodr = 0; bodr < 3; ++bodr)
                    if (good[bodl][bodr])
                    {
                        dp[pos][i][j] += dp[childLeft][i][bodl] * dp[childRight][bodr][j];
                        dp[pos][i][j] %= mod;
                    }

}

long long getRes()
{
    long long res = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            res += dp[0][i][j], res %= mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    fastInOut scanner;
    n = scanner.nextInt();
    m = scanner.nextInt();

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            good[i][j] = scanner.nextInt();


    build(0, 0, n - 1);

    for (int i = 0; i < m; ++i)
    {
        int v, t;
        v = scanner.nextInt();
        t = scanner.nextInt();
        --v;
        --t;
        update(0, 0, n - 1, v, t);
        scanner.printLongLong(getRes());
        scanner.printLn();
    }



    return 0;
}