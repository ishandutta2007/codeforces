#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    vector<bool> p(300000000 + 1, true);
    p[0] = p[1] = false;
    for(int i = 2; i <= r; i += 2) p[i] = false;
    for(int i = 3; i * i <= r; i += 2)
            if(p[i])
                    for(int j = i * i; j <= r; j += (i << 1))
                            p[j] = false;
    int res = 0;
    for(int i = 5; i <= r; i += 4)
            if(p[i] && i >= l && i <= r)
                    ++res;
    if(l <= 2 && r >= 2)
         ++res;
    cout << res;
    cin >> l;
    return 0;
}