#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector <ll> seq;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i * i <= n; i++) if (n % i == 0) {
        ll a = i, b = n / i;
        seq.push_back((2ll + (a - 1) * b) * a / 2);
        seq.push_back((2ll + (b - 1) * a) * b / 2);
    }
    sort(seq.begin(), seq.end()); seq.erase(unique(seq.begin(), seq.end()), seq.end());
    for (int i = 0; i < seq.size(); i++)
        printf("%I64d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    return 0;
}