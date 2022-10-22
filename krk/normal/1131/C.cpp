#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int n;
int a[Maxn];
deque <int> seq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    seq.push_back(a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
        if (seq.front() >= seq.back()) seq.push_front(a[i]);
        else seq.push_back(a[i]);
    for (int i = 0; i < seq.size(); i++)
        printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    return 0;
}