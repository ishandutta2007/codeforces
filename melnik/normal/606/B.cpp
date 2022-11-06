//
//  main.cpp
//  Olympiads
//
//  Created by Melnik on 06.12.15.
//  Copyright  2015 Melnik. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <iomanip>
#include <iterator>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 1111;
const int M = 1000500;

int n, m;
int x, y;
bool used[N][N];
char s[M];

bool canGo(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return false;
    return true;
}

int main() {
    scanf("%d%d%d%d\n", &n, &m, &x, &y);
    gets(s + 1);
    int len = (int)strlen(s + 1);
    printf("1 ");
    int dx, dy;
    dx = dy = 0;
    used[x][y] = true;
    for (int i = 1; i <= len; i++) {
        dx = dy = 0;
        if (s[i] == 'D') dx = 1;
        if (s[i] == 'U') dx = -1;
        if (s[i] == 'L') dy = -1;
        if (s[i] == 'R') dy = 1;
        if (i == len) {
            int res = 0;
            for (int ii = 1; ii <= n; ii++) for (int j = 1; j <= m; j++) if (!used[ii][j]) res++;
            printf("%d\n", res);
            break;
        }
        if (canGo(x + dx, y + dy)) {
            if (used[x + dx][y + dy]) printf("0 "); else printf("1 ");
            x += dx;
            y += dy;
            used[x][y] = true;
        } else printf("0 ");
    }
    return 0;
}