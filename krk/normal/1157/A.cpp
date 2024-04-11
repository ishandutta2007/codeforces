#include <bits/stdc++.h>
using namespace std;

set <int> was;

int n;

int main()
{
    cin >> n;
    while (was.find(n) == was.end()) {
        was.insert(n);
        n++;
        while (n % 10 == 0) n /= 10;
    }
    printf("%d\n", int(was.size()));
    return 0;
}