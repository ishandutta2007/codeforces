#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

char A[100001],B[100001];
int L,p,q,r;

int main()
{
    int i;

    scanf ("%s %s",A,B);
    L = strlen(A);

    for (i=0;i<L;i++) if (A[i] != B[i]){
        if (A[i] == '4') p++;
        else q++;
    }
    r = min(p,q);
    printf ("%d",p+q-r);

    return 0;
}