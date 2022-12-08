#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

long long N,MIN,MAX;

int main()
{
    long long i,j,k;

    MIN = 1e17; MAX = -1;
    scanf ("%lld",&N);
    for (i=1;;i++){
        if (i > N / i) break;
        if (N % i != 0) continue;
        for (j=i;j<=N/i;j++){
            k = N / i / j;
            if (j > k) break;
            if ((N / i) % j != 0) continue;
            MIN = min(MIN,(i+2)*(j+2)*(k+1)-N);
            MIN = min(MIN,(i+2)*(k+2)*(j+1)-N);
            MIN = min(MIN,(j+2)*(k+2)*(i+1)-N);
            MAX = max(MAX,(i+2)*(j+2)*(k+1)-N);
            MAX = max(MAX,(i+2)*(k+2)*(j+1)-N);
            MAX = max(MAX,(j+2)*(k+2)*(i+1)-N);
        }
    }
    printf ("%lld %lld",MIN,MAX);

    return 0;
}