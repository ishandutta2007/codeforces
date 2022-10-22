#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int A, B;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &A, &B);
        int cnt = 0;
        ll cur = 0;
        while (true) {
            cur = 10ll * cur + 9ll;
            if (cur <= B) cnt++;
            else break;
        }
        cout << ll(A) * cnt << endl;
    }
    return 0;
}