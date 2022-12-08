#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

long long ans;
int N,A[200050],X[200050],C[400100];
map<int, vector<int> > fac;

int gcd(int a, int b)
{
    return b ? gcd(b,a%b) : a;
}

void test(int k)
{
    vector<int> &f = fac[k];
    for (int i=0;i<k;i++) X[i] = A[i];
    for (int i=k;i<N;i++) if (X[i%k] < A[i]) X[i%k] = A[i];
    for (int i=0;i<N*2;i++) C[i] = X[i%k] == A[i%N];
    int c = 0;
    for (int i=0;i<N*2;i++){
        if (C[i]) c++;
        else c = 0;
        if (i >= N){
            ans += upper_bound(f.begin(),f.end(),c) - f.begin();
        }
    }
}

int main()
{
    scanf ("%d",&N);
    for (int i=0;i<N;i++) scanf ("%d",&A[i]);
    for (int i=1;i<N;i++) fac[gcd(i,N)].push_back(i);
    for (int i=1;i*i<=N;i++) if (N % i == 0){
        test(i);
        if (i * i != N && i != 1) test(N/i);
    }

    printf ("%lld\n",ans);

    return 0;
}