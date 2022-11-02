#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

typedef long long lld;

#define MAXN 1000006

lld N,M,all,sum;
int P,Q,G,C[MAXN][26];
char A[MAXN],B[MAXN];

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int main()
{
    int i;
    cin >> N >> M;
    scanf("%s%s",A,B);
    P = strlen(A), Q = strlen(B);
    G = gcd(P,Q);
    for (i=0;i<P;i++) C[i%G][A[i]-'a']++;
    for (i=0;i<Q;i++) sum += C[i%G][B[i]-'a'];
    sum *= N/(Q/G);
    all = P*N;
    cout << all-sum << endl;
}