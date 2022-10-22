#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;
set <int> S;
vector <vector <int> > pr;

void genDivs(int n)
{
    for (int i = 1; i * i <= n; i++) if (n % i == 0) {
        S.insert(i);
        S.insert(n / i);
    }
}

void genPrimes(int n)
{
    for (int i = 2; i * i <= n; i++) if (n % i == 0) {
        vector <int> tmp = {i};
        pr.push_back(tmp);
        while (n % i == 0) n /= i;
    }
    if (n > 1) {
        vector <int> tmp = {n};
        pr.push_back(tmp);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        S.clear();
        pr.clear();
        genDivs(n);
        genPrimes(n);
        for (int i = 0; i < pr.size(); i++)
            S.erase(pr[i][0]);
        int res = 0;
        if (pr.size() == 1) ;
        else if (pr.size() == 2) {
            pr[0].push_back(pr[0][0] * pr[1][0]);
            S.erase(pr[0][0] * pr[1][0]);
            if (n % (ll(pr[0][0]) * pr[0][0]) == 0 && ll(pr[0][0]) * pr[0][0] * pr[1][0] <= n) {
                pr[1].push_back(pr[0][0] * pr[0][0] * pr[1][0]);
                S.erase(pr[0][0] * pr[0][0] * pr[1][0]);
            } else if (n % (ll(pr[1][0]) * pr[1][0]) == 0 && ll(pr[0][0]) * pr[1][0] * pr[1][0] <= n) {
                pr[1].push_back(pr[0][0] * pr[1][0] * pr[1][0]);
                S.erase(pr[0][0] * pr[1][0] * pr[1][0]);
            } else res = 1;
        } else
            for (int i = 0; i < pr.size(); i++) {
                int ni = (i + 1) % int(pr.size());
                pr[i].push_back(pr[i][0] * pr[ni][0]);
                S.erase(pr[i][0] * pr[ni][0]);
            }
        for (auto num: S)
            for (int i = 0; i < pr.size(); i++)
                if (num % pr[i][0] == 0) {
                    pr[i].push_back(num);
                    break;
                }
        bool wr = false;
        for (int i = 0; i < pr.size(); i++) {
            for (int j = 0; j < pr[i].size(); j++) if (j != 1) {
                if (wr) printf(" ");
                else wr = true;
                printf("%d", pr[i][j]);
            }
            if (pr[i].size() > 1) {
                if (wr) printf(" ");
                else wr = true;
                printf("%d", pr[i][1]);
            }
        }
        printf("\n%d\n", res);
    }
    return 0;
}