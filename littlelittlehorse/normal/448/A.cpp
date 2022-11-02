#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int cnt1, cnt2, n;

int main(){
    cnt1 = 0;
    for (int i = 1; i <= 3; i++)
    {
        int x;
        scanf("%d", &x);
        cnt1 += x;
    }
    cnt2 = 0;
    for (int i = 1; i <= 3; i++)
    {
        int x;
        scanf("%d", &x);
        cnt2 += x;
    }
    scanf("%d", &n);
    int use = 0;
    use += cnt1 / 5;
    if ((cnt1 % 5)) ++use;
    use += cnt2 / 10;
    if ((cnt2 % 10)) ++use;
    if (use <= n) printf("YES\n");
    else printf("NO\n");
}