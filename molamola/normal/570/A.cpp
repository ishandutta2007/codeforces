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
int a[101][101], ans[101], p[101];

int main(){
    int n, m;
    scanf("%d%d",&m,&n);
    rep1(i, n)rep1(j, m)scanf("%d",a[i]+j), ans[i] = 1;
    rep1(i, n)rep1(j, m){
        if(a[i][ans[i]] < a[i][j])ans[i] = j;
    }
    rep1(i, n)p[ans[i]]++;
    int res = 0;
    p[0] = -1;
    rep1(i, m){
        if(p[res] < p[i])res = i;
    }
    printf("%d",res);
    return 0;
}