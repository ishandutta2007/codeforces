#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
int n,a[110],minnum=2e9,l,r;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++) if(abs(a[i]-a[i+1])<minnum) l=i,r=i+1,minnum=abs(a[i]-a[i+1]);
    if(abs(a[n]-a[1])<minnum) l=n,r=1;
    printf("%d %d\n",l,r);
    return 0;
}