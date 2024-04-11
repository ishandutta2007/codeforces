#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int n;
int p[100010];
ll d[100010];

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        p[x]++;
    }
    d[1] = p[1];
    d[2] = p[2]+p[2];
    for(i=3;i<=100000;i++){
        d[i] = max(d[i-2], d[i-3]) + (ll)p[i] * i;
    }
    printf("%lld",max(d[100000], d[99999]));
    return 0;
}