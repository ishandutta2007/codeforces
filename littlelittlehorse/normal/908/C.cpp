#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int N(1111);
int x[N];
double y[N];

int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    for(int i(1); i <= n; i++) {
        scanf("%d", &x[i]);
        y[i] = r;
        for(int j(1); j < i; j++) {
            if(abs(x[i] - x[j]) <= 2 * r) {
                y[i] = max(y[i], y[j] + sqrt(max(0., 4. * r * r - abs(x[i] - x[j]) * abs(x[i] - x[j]))));
            }
        }
        printf("%.12f%c", y[i], i == n ? '\n' : ' ');
    }
}