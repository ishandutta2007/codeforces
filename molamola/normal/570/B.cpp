#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

#define rep0(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rep(i,x,y) for(int i=x;i<y;i++)
#define pb(x) push_back(x)

typedef long long ll;

char c[300030];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    if(n == 1)printf("1");
    else if (m - 1 >= n - m)printf("%d", m - 1);
    else printf("%d", m + 1);
    return 0;
}