#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        priority_queue <int> Q;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            Q.push(a);
        }
        int old = 0;
        int tims = 0;
        while (!Q.empty()) {
            int v = Q.top(); Q.pop();
            tims++;
            if (old) Q.push(old);
            old = v - 1;
        }
        printf("%s\n", tims % 2? "T": "HL");
    }
    return 0;
}