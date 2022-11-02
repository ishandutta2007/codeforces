#include <stdio.h>
#include <set>
using namespace std;

set <int> S;

int main()
{
    int i,k;
    for (i=0;i<4;i++) scanf("%d",&k), S.insert(k);
    printf("%d",4-S.size());
}