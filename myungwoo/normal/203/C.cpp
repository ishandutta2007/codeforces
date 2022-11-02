#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100005

int N,D,A,B;
vector <int> arr;

struct Z{
    int x,y,c,n;
    bool operator < (const Z &b)const{ return c<b.c; }
} P[MAXN];

int main()
{
    int i;
    scanf("%d%d%d%d",&N,&D,&A,&B);
    for (i=1;i<=N;i++) scanf("%d%d",&P[i].x,&P[i].y), P[i].c = P[i].x*A+P[i].y*B, P[i].n = i;
    sort(P+1,P+N+1);
    for (i=1;i<=N;i++){
        if (D >= P[i].c) D -= P[i].c, arr.push_back(P[i].n);
        else break;
    }
    printf("%d\n",arr.size());
    for (i=arr.size();i--;) printf("%d ",arr[i]);
}