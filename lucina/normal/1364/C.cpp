#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int lim = 1e6;
int a[nax];
int b[nax];
int n;

int main () {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }

    int mex = 0;
    vector <int> wait ;

    for (int i = 1 ; i <= n ; ++ i) {
        wait.push_back(i);
        while (a[i] > mex) {
            if (wait.empty()) return !printf("-1");
            b[wait.back()] = mex ++;
            wait.pop_back();
        }
    }

    for (int i : wait) {
        b[i] = lim;
    }

    for (int i = 1 ; i <= n ; ++ i)
        printf("%d ", b[i]);
}