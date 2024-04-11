#include <iostream>
#include <utility>
#include <queue>
#define N (1 << 16)

using namespace std;

queue<pair<int, int>> q;
int deg[N], _xor[N];

void process(int a)
{
    if (deg[a] != 1)
        return;
    --deg[_xor[a]];
    _xor[_xor[a]] ^= a;
    process(_xor[a]);
    q.push(make_pair(a, _xor[a]));
    --deg[a];
    _xor[a] = 0;
}

int main()
{
    int a, b, n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        deg[i] += a;
        _xor[i] ^= b;
        process(i);
    }
    cout << q.size() << '\n';
    while (q.size())
    {
        cout << q.front().first << ' ' << q.front().second << '\n';
        q.pop();
    }
    return 0;
}