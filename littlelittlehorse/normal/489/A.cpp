#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[3001];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%d\n", n - 1);
    for (int i = 1; i < n; i++)
    {
        int pos = i;
        for (int j = i + 1; j <= n; j++)
            if (a[j] < a[pos]) pos = j;
        printf("%d %d\n", i - 1, pos - 1);
        swap(a[i], a[pos]);
    }
}