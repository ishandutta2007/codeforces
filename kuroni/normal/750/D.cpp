#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <ios>
#define ll long long

using namespace std;

const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}, lim = 150;

bool way[301][301][31][8], chk[301][301];
int n, t[31], i, ans = 0;

void DFS(int starting_pos_x, int starting_pos_y, int direction, int step)
{
    int i;
    way[starting_pos_x][starting_pos_y][step][direction] = 1;
    for (i = 0; i < t[step]; i++)
    {
        starting_pos_x += dx[direction];
        starting_pos_y += dy[direction];
        ans += (!chk[starting_pos_x][starting_pos_y]);
        chk[starting_pos_x][starting_pos_y] = 1;
    }
    if (step < n)
    {
        if (!way[starting_pos_x][starting_pos_y][step + 1][(direction + 1) % 8])
            DFS(starting_pos_x, starting_pos_y, (direction + 1) % 8, step + 1);
        if (!way[starting_pos_x][starting_pos_y][step + 1][(direction + 7) % 8])
            DFS(starting_pos_x, starting_pos_y, (direction + 7) % 8, step + 1);
    }
}

int main()
{
    memset(way, 0, sizeof(way));
    memset(chk, 0, sizeof(chk));
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &t[i]);
    DFS(150, 150, 0, 1);
    printf("%d", ans);
}