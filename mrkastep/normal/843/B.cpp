#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <complex>
#include <map>
#include <set>
#include <time.h>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

const int inf = 2e9;
const ll LONGINF = 8e18;
const int MAXN = 110;

int nxt[100100], val[100100];


pair<int, int> ask(int i) {
    printf("? %d\n", i);
    fflush(stdout);
    int a, b;
    scanf("%d %d", &a, &b);
    if(a == -1 && b == -1)
        exit(0);
    return {a, b};
}

void push(int a) {
    printf("! %d\n", a);
    fflush(stdout);
}

void solve() {
    int n, start, x;
    cin >> n >> start >> x;
    for(int i = 0; i < n + 1; ++i) {
        nxt[i] = inf, val[i] = inf;
    }
    auto p = ask(start);
    nxt[start] = p.second;
    val[start] = p.first;
    if(val[start] >= x) {
        push(val[start]);
        return;
    }
    for(int i = 1; i < min(n, 1000); ++i) {
        int q = (rand() * rand() + rand()) % n + 1;
        while(nxt[q] != inf) {
            q = q % n + 1;
        }
        p = ask(q);
        nxt[q] = p.second;
        val[q] = p.first;
    }
    map<int, int> pos;
    for(int i = 1; i <= n; ++i) {
        if(nxt[i] != inf) {
            pos[val[i]] = i;
            if(val[i] == x) {
                push(x);
                return;
            }
        }
    }
    auto it = pos.lower_bound(x);
    if(it != pos.end() && it->first == x) {
        push(x);
        return;
    }
    start = nxt[prev(it)->second];
    while(1) {
        if(start == -1) {
            push(-1);
            return;
        }
        auto p = ask(start);
        if(p.first >= x) {
            push(p.first);
            return;
        }
        start = p.second;
    }


}

int main() {
//#ifdef _DEBUG
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    srand(time(0));
    solve();
    return 0;
}