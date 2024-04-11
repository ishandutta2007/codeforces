#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a;
int freq[2];
ll pos;

int main()
{
    scanf("%d", &n);
    freq[0] = 1;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a < 0) cur = 1 - cur;
        pos += freq[cur]++;
    }
    cout << ll(n) * (n + 1) / 2 - pos << " " << pos << endl;
    return 0;
}