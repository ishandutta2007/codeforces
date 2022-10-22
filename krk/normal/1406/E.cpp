#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100001;
 
int n;
bool prime[Maxn];
int mx[Maxn];
vector <int> pr;
bool has[Maxn];
int cur;
bool cant[Maxn];
 
int getA(int a)
{
    printf("A %d\n", a); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}
 
int getB(int a)
{
    printf("B %d\n", a); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}
 
void getC(int a)
{
    printf("C %d\n", a); fflush(stdout);
}

void addCant(int val)
{
    for (int i = val; i <= n; i += val)
        cant[i] = true;
}
 
int Solve(int val, int from)
{
    int res = val;
    int mult = 2;
    while (mult * val <= n)
        if (cant[mult * val]) { addCant(mult * val); mult++; }
        else if (getA(mult * val) > 0) {
            val *= mult;
            res = val;
            mult = 2;
        } else { addCant(mult * val); mult++; }
    return res;
}
 
int main()
{
    scanf("%d", &n);
    fill(prime + 2, prime + n + 1, true);
    for (int i = 2; i <= n; i++) if (prime[i]) {
        pr.push_back(i);
        for (int j = i; j <= n; j += i) {
            prime[j] = false;
            mx[j] = i;
        }
    }
    fill(has + 1, has + n + 1, true);
    cur = n;
    int sz = pr.size();
    while (sz > 0) {
        int tk = (sz + 1) / 2;
        for (int i = 1; i <= tk; i++) {
            int num = pr[sz - i];
            getB(num);
            for (int j = num; j <= n; j += num)
                if (has[j]) {
                    has[j] = false;
                    cur--;
                }
        }
        if (getA(1) != cur) {
            int from = pr[sz - tk], val = 1;
            for (int i = tk; i > 0; i--) {
                int num = pr[sz - i];
                if (getA(num) > 0)
                    val *= num;
                else addCant(num);
            }
            getC(Solve(val, from));
            return 0;
        } else for (int i = tk; i > 0; i--)
                addCant(pr[sz - i]);
        sz -= tk;
    }
    getC(1);
    return 0;
}