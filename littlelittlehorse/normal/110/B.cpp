#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main(){
    // freopen("b.in", "r", stdin);
    // freopen("b.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 1; i <= n / 4; i++) printf("abcd");
     for (int i = 1; i <= n % 4; i++)
          printf("%c", 'a' + i - 1);
     printf("\n");
}