#include <stdio.h>
#include <set>
using namespace std;

#define MAXN 100005

int N,A[MAXN],B[MAXN],P[MAXN];

multiset <int> S;
multiset <int>::iterator it;

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for (i=0;i<N;i++) scanf("%d",A+i), P[A[i]] = i;
    for (i=0;i<N;i++) scanf("%d",B+i), S.insert(i-P[B[i]]);
    for (i=0;i<N;i++){
        it = S.lower_bound(i);
        k = 1e9;
        if (it != S.end()) k = *it-i;
        if (it != S.begin()) k = min(k,i-*(--it));
        printf("%d\n",k);
        S.erase(S.find(i-P[B[i]]));
        S.insert(i+N-P[B[i]]);
    }
}