#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

char str[111];

int main() {
    scanf("%s", str);
    int n = strlen(str), ans = 0;
    for (int i = 0; i < n; i++)
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' 
            || str[i] == 'o' || str[i] == 'u')
                ++ans;
        else
            if (str[i] >= '0' && str[i] <= '9')
                ans += (str[i] - '0') & 1;
    printf("%d\n", ans);
}