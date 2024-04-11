#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 52;

char res[Maxn][Maxn];
int A, B, C, D;

ii Get(int wh, int ind)
{
    int r = 1 + 2 * (ind / 24);
    int c = 1 + 2 * (ind % 24);
    r += wh * 11;
    return ii(r, c);
}

int main()
{
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("44 49\n");
    for (int i = 0; i < 44; i++)
        for (int j = 0; j < 49; j++)
            res[i][j] = i / 11 + 'A';
    for (int i = 0; i < A - 1; i++) {
        auto got = Get(3, i);
        res[got.first][got.second] = 'A';
    }
    for (int i = 0; i < B - 1; i++) {
        auto got = Get(0, i);
        res[got.first][got.second] = 'B';
    }    
    for (int i = 0; i < C - 1; i++) {
        auto got = Get(1, i);
        res[got.first][got.second] = 'C';
    }    
    for (int i = 0; i < D - 1; i++) {
        auto got = Get(2, i);
        res[got.first][got.second] = 'D';
    }
    for (int i = 0; i < 44; i++) {
        res[i][49] = '\0';
        printf("%s\n", res[i]);
    }
    return 0;
}