#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const int MAXN = 50010;

char str[MAXN], res[MAXN];
int n;
ll a[MAXN][2];
priority_queue<pli> pq;
int cur, cnt;
ll cst;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%s%n", str, &n);
    for (int i=0; i<n; i++) res[i] = str[i];
    for (int i=0; i<n; i++) scanf("%I64d %I64d", &a[i][0], &a[i][1]);
    for (int i=0; i<n; i++) {
        if (str[i]=='(') cur++;
        else if (str[i] == ')') cur--;
        else {
            cur--; cst += a[cnt][1];
            pq.push(pli(-(a[cnt][0] - a[cnt][1]), i));
            res[i] = ')';
            cnt++;
        }
        while (cur < 0) {
            cur += 2;
            if (pq.empty()) {
                printf("-1\n");
                return 0;
            }
            cst -= pq.top().first;
            res[pq.top().second] = '(';
            pq.pop();
        }
    }
    if (cur > 0) printf("-1\n");
    else {
        printf("%I64d\n%s\n", cst, res);
    }
}