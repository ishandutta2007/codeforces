#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
char str[100011];

int main(){
    //freopen("c.in", "r", stdin);
    scanf("%d%d%s", &n, &m, str + 1);
    int ans = 0, Min = 1 << 30, Max = -Min;
    for (int i = 1, j = n; i < j; i++, j--)
        if (str[i] != str[j]) 
        {
            ans += abs(min(abs(str[i] - str[j]), 26 - abs((str[i] - str[j]))));
            Min = min(Min, i); Max = max(Max, i);
        }
    if (m > n / 2) m = n - m + 1;
    if (Min == 1 << 30);
    else if (Min >= m) ans += Max - m;
    else if (Max <= m) ans += m - Min;
    else ans += Max - Min + min(Max - m, m - Min);
    printf("%d\n", ans);
}