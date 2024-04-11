#include <bits/stdc++.h>
using namespace std;

bool visit[11];
int record[1005];
int m;

bool dfs(int turn, int left, int right, int times, int front)
{
    if (times)
        if (turn)
        {
            if (left <= right)
                return false;
        }
        else if (left >= right)
            return false;
    if (times == m)
    {
        puts("YES");
        for (int i = 0; i < times; i++)
            printf("%d ", record[i]);
        puts("");
        return true;
    }
    bool check = false;
    for (int i = 1; i <= 10; i++)
        if (visit[i] && i != front)
        {
            record[times] = i;
            if (!turn)
                check |= dfs(!turn, left + i, right, times + 1, i);
            else
                check |= dfs(!turn, left, right + i, times + 1, i);
            if (check)
                return true;
        }
    return check;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 10; i; i--)
    {
        visit[i] = t % 10;
        t /= 10;
    }
    scanf("%d", &m);
    if (!dfs(0, 0, 0, 0, -1))
        puts("NO");
    return 0;
}