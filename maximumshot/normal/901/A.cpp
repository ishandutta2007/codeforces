#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef long double ld;

#define info(x) cerr << #x << " = " << x << endl
#define vec vector
#define ALL(x) (x).begin(), (x).end()

int const inf = 1e9;
ll const inf64 = 1e18;

const int H = 1e5 + 5;

int h;
int a[H];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &h);

    int any = -1;
    int sum = 0;

    for(int i = 0;i <= h;i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        if(any == -1) {
            if(i > 0 && a[i - 1] > 1 && a[i] > 1) {
                any = i;
            }
        }
    }

    if(any == -1) {
        puts("perfect");
        return 0;
    }

    puts("ambiguous");

    for(int i = 1;i <= h + 1;i++) {
        printf("%d ", i - 1);
    }

    for(int i = 0;i <= h;i++) {
        for(int j = 1;j < a[i];j++) {
            printf("%d ", i);
        }
    }

    printf("\n");

    for(int i = 1;i <= h + 1;i++) {
        printf("%d ", i - 1);
    }

    printf("%d %d ", any - 1, h + 2);

    a[any]--;
    a[any - 1]--;

    for(int i = 0;i <= h;i++) {
        for(int j = 1;j < a[i];j++) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}