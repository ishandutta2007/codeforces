#include <bits/stdc++.h>
using namespace std;
int a[1000];
bool check(int t) {
    bool mark = true;
    for ( int k = 0; k < t; k++) {
        if ( a[k] != a[t - k]) {
            mark = false;
        }
    }
    return mark;
}
int main()
{   ios_base::sync_with_stdio(0);
    int x;
    cin >> x;
    int i = 0;
    while (x > 0) {
        a[i] = x % 10;
        x = x/10;
        i++;
    }
    i--;
    bool mark1 = false;
    for (int j = 0; j <= 100; j++) {
        if (check(j + i)) mark1 = true;
    }
    if ( mark1 ) {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}