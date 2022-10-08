#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long LL;

char t[9][9];

bool allBlack(int y) {
    for (int x = 0; x < 8; ++x)
        if (t[y][x] != 'B')
            return 0;
    return 1;
}

int main() {
    for (int i = 0; i < 8; ++i)
        scanf("%s", t[i]);
    int res = 0;
    for (int i = 0; i < 8; ++i)
        res += allBlack(i);
    if (res == 8) {
        printf("%d\n", res);
        return 0;
    }
    for (int i = 0; i < 8; ++i)
        for (int j = i + 1; j < 8; ++j)
            swap(t[i][j], t[j][i]);
    for (int i = 0; i < 8; ++i)
            res += allBlack(i);
    printf("%d\n", res);
}