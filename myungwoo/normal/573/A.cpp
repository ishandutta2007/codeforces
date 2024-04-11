#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define pb push_back

int N, A[MAXN];
bool V[32000];
vector <int> primes;

vector <int> f(int n)
{
    vector <int> ret;
    for (int t: primes){
        if (t*t > n) break;
        while (n % t == 0){
            if (t > 3) ret.pb(t);
            n /= t;
        }
    }
    if (n > 3) ret.pb(n);
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%d", A+i);
    primes.pb(2);
    for (int i=3;i<32000;i+=2) if (!V[i]){
        primes.pb(i);
        for (int j=i*i;j<32000;j+=i+i) V[j] = 1;
    }
    vector <int> a = f(A[1]);
    for (int i=2;i<=N;i++){
        auto b = f(A[i]);
        if (a != b){ puts("No"); return 0; }
    }
    puts("Yes");
}