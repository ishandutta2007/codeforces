#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int Maxm = 794;
 
vector <int> pr;
vector <int> ch;
bool prime[Maxm];
int T;
 
ll Ask(ll q)
{
    printf("? %I64d\n", q); fflush(stdout);
    ll res; scanf("%I64d", &res);
    return res;
}
 
int main()
{
    fill(prime + 2, prime + Maxm, true);
    for (int i = 2; i < Maxm; i++) if (prime[i]) {
        pr.push_back(i);
        for (int j = i + i; j < Maxm; j += i)
            prime[j] = false;
    }
    for (int i = 0; i < pr.size(); i++) {
        int num = 1;
        while (num <= 1586 / pr[i])
            num *= pr[i];
        ch.push_back(num);
    }
    scanf("%d", &T);
    while (T--) {
        ll dvs = 1;
        for (int i = 0, to; i < pr.size(); i = to) {
            to = i;
            ll ask = 1;
            while (to < pr.size() && ask <= 1000000000000000000ll / ch[to])
                ask *= ch[to++];
            ll got = Ask(ask);
            for (int j = i; j < to; j++) {
                int cnt = 0;
                while (got % pr[j] == 0) {
                    got /= pr[j];
                    cnt++;
                }
                dvs *= (cnt + 1);
            }
        }
        printf("! %I64d\n", dvs * 2ll); fflush(stdout);
    }
    return 0;
}