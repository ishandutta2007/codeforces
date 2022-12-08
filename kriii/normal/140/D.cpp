#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int N,R[111],T=10,PR,PN;

int main()
{
    int i;

    scanf ("%d",&N);
    for (i=0;i<N;i++) scanf ("%d",&R[i]);
    sort(R,R+N);
    for (i=0;i<N;i++){
        T += R[i];
        if (T > 720) break;
        if (T > 360) PN += T - 360;
        PR++;
    }
    printf ("%d %d",PR,PN);

    return 0;
}