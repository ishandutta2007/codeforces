#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
    
using namespace std;

template<typename T> T nextInt() {
    char c;
    T x = 0, p = 1;
    do { c = getchar(); } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x * p;
}

int i, j;

int main() {
    //freopen("input.txt", "r", stdin);

    printf("%d\n", 1999);
    for (int j = 1; j <= 2; j++) {
        for (int i = j; i <= 1000; i++) {
            printf("%d %d %d %d\n", i, 1, i, 2);
        }
    }
   
    return 0;
}