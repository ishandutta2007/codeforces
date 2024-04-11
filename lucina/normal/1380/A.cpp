#include<cstdio>
#include<algorithm>
int n;
int a[1 << 10];  

void solve () {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }
    for (int i = 2 ; i < n ; ++ i) {
        if (a[i] > std::max(a[i - 1], a[i + 1])) {
            puts("YES");
            printf("%d %d %d\n", i - 1, i, i + 1);
            return ;
        }
    }
    
    puts("NO");
    
}

int main () {
    int T;
    
    for (scanf("%d", &T) ; T -- ; ) {
        solve();
    }
}