#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int f[5][5];
char str[1111111];

int calc(int n){
    int Left = 0, len = strlen(str);
    for (int i = 0; i < len; i++)
        Left = (Left * 10 + str[i] - '0') % n;
    return Left;
}

int main(){
    for (int i = 1; i <= 4; i++)
    {
        f[i][0] = 1;
        for (int j = 1; j <= 4; j++) f[i][j] = f[i][j - 1] * i % 5;
    }
    scanf("%s", str);
    printf("%d\n", (1 + f[2][calc(4)] + f[3][calc(4)] + f[4][calc(4)]) % 5);
}