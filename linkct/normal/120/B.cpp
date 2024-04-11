#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

bool v[1010];

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d",&x);
        v[i] = (x == 1);
    }
    for (; ; k++) {
        if (k == n + 1)
            k = 1;
        if (v[k]) {
            printf("%d\n",k);
            return 0;
        }
    }
    return 0;
}