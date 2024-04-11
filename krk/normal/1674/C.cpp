#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
string A, B;

int main()
{
    cin >> T;
    while (T--) {
        cin >> A >> B;
        if (B == "a") printf("1\n");
        else {
            bool has = false;
            for (int i = 0; i < B.length(); i++)
                if (B[i] == 'a') has = true;
            if (has) printf("-1\n");
            else {
                ll res = 1;
                for (int i = 0; i < A.size(); i++)
                    res *= 2;
                printf("%I64d\n", res);
            }
        }
    }
    return 0;
}