#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 100010;
typedef long long LL;
int n, m, x, d;
LL sum = 0, MAX = 0, MIN = 0;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        MAX += abs(i - 1);
        MIN += abs(i - (n + 1) / 2);
    }
    for(int i = 1; i <= m; i++){
        int x, d; scanf("%d%d", &x, &d);
        if(d > 0) sum += x * n + d * MAX;
        else sum += x * n + d * MIN;
    }
    printf("%.15f", double(sum) / n);
    return 0;
}