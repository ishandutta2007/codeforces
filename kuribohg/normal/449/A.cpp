#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
long long n,m,k;
long long ans;
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    if(k>n+m-2) {puts("-1");return 0;}
    if(n<m) swap(n,m);
    if(k<n) ans=max(m*(n/(k+1)),n*(m/(k+1)));
    else ans=max(m/(k-n+2),n/(k-m+2));
    printf("%I64d\n",ans);
    return 0;
}