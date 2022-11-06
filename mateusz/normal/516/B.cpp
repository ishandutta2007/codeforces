#include <bits/stdc++.h>

using namespace std;
const int N = 2005;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool odw[N][N];
char board[N][N];
char ans[N][N];
pair<int, int> ktory[N][N];
int n, m;
queue<pair<int, int > > Q;
bool jednaopcja(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m || odw[x][y] || board[x][y] == '*') return false;
    int liczbaopcji = 0;
    for(int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && odw[xx][yy] == false && board[xx][yy] == '.')
            liczbaopcji++;
    }
    return liczbaopcji == 1;
}

pair<int, int> ktora_opcja(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && odw[xx][yy] == false && board[xx][yy] == '.')
            return {xx, yy};
    }
    return {-1, -1};
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%s", &board[i][1]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(jednaopcja(i, j))
            { 
                odw[i][j] = true;
                pair<int, int> para = ktora_opcja(i, j);
                ktory[i][j] = para;
                odw[para.first][para.second] = true;
                Q.push({i, j});
            }
        }
    }
    
    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        pair<int, int> sasiad = ktory[x][y];
        int xs = sasiad.first;
        int ys = sasiad.second;
        if(x == xs + 1)
        {
            ans[x][y] = 'v';
            ans[xs][y] = '^';
        }
        if(x == xs - 1)
        {
            ans[x][y] = '^';
            ans[xs][y] = 'v';
        }
        if(y == ys + 1)
        {
            ans[x][y] = '>';
            ans[x][ys] = '<';
        }
        if(y == ys - 1)
        {
            ans[x][y] = '<';
            ans[x][ys] = '>';
        }
        for(int i = 0; i < 4; i++)
        {
            int xx = xs + dx[i];
            int yy = ys + dy[i];
            if(jednaopcja(xx, yy))
            {
                odw[xx][yy] = true;
                pair<int, int> para = ktora_opcja(xx, yy);
                odw[para.first][para.second] = true;
                ktory[xx][yy] = para;
                Q.push({xx, yy});
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(odw[i][j] == false && board[i][j] == '.')
            {
                printf("Not unique\n");
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int  j = 1; j <= m; j++)
        {
            if(board[i][j] == '*')
                printf("*");
            else
                printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}