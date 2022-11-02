#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
#include <cstdio>
using namespace std;

const long long inf = 1e15;

long long Abs(long long n) {
     return n > 0 ? n : -n;
}

int main() {
    long long n, m;
    cin >> n >> m;
    long long x, y;
    cin >> x >> y;
    long long k;
    cin >> k;
    long long dx[k], dy[k];
    for(int i = 0; i < k; ++i)
            cin >> dx[i] >> dy[i];
    long long res = 0;
    for(int i = 0; i < k; ++i) {
            long long stepX, stepY;
            if(dx[i] == 0)
                     stepX = inf;
            if(dx[i] > 0)
                     stepX = (n - x) / Abs(dx[i]);
            if(dx[i] < 0)
                     stepX = (x - 1) / Abs(dx[i]);
            if(dy[i] == 0)
                     stepY = inf;
            if(dy[i] > 0)
                     stepY = (m - y) / Abs(dy[i]);
            if(dy[i] < 0)
                     stepY = (y - 1) / Abs(dy[i]);
            long long step = min(stepX, stepY);
            x += dx[i] * step;
            y += dy[i] * step;
            res += step;
    }
    cout << res;
    cin >> n;
    return 0;        
}