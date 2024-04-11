#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> chk;
int N,N2,A[250005],U[505];

int gcd(int a, int b)
{
    return b ? gcd(b,a%b) : a;
}

int main()
{
    scanf ("%d",&N); N2 = N*N;
    for (int i=0;i<N2;i++) scanf ("%d",&A[i]);
    sort(A,A+N2);
    reverse(A,A+N2);

    for (int i=0,j=0;i<N2;i++){
        if (!chk.count(A[i])){
            U[j] = A[i];
            for (int k=0;k<j;k++) chk[gcd(U[k],U[j])] += 2;
            j++;
        }
        else{
            int &r = chk[A[i]];
            if (--r == 0) chk.erase(A[i]);
        }
    }
    for (int i=0;i<N;i++) printf ("%d ",U[i]);

    return 0;
}