#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long n;

int main(){
    //freopen("a.in", "r", stdin);
    scanf("%I64d", &n);
    if (!(n & 1)) printf("%I64d\n", n / 2);
    else printf("%I64d\n", n / 2 - n);
}