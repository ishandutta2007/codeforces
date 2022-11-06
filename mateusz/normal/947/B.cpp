#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
int v[N], t[N];

int main() {

    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    
    long long sumT = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        sumT += t[i];
    }
    
    priority_queue<long long> Q;
    for (int i = 1; i <= n; i++) {
        Q.push(-(v[i] - sumT));
        long long melt = 0;
        while (!Q.empty() && -Q.top() + sumT - t[i] <= 0) {
            melt += -Q.top() + sumT;
            Q.pop();
        }
        melt += (long long)t[i] * Q.size();
        printf("%lld ", melt);
        sumT -= t[i];
    }
    
    return 0;
}