#include <bits/stdc++.h>
using namespace std;

int n, k;
set <int> S;
deque <int> D;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (S.find(a) == S.end()) {
            if (D.size() >= k) { S.erase(D.front()); D.pop_front(); }
            D.push_back(a); S.insert(a);
        }
    }
    printf("%d\n", int(D.size()));
    for (int i = int(D.size()) - 1; i >= 0; i--)
        printf("%d%c", D[i], i - 1 >= 0? ' ': '\n');
    return 0;
}