#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int n, M;
    int m[500006];
    int s[500006];
    cin>>n>>M;
    for (int i=0;i<n;i++) scanf("%d", &m[i]);
    int l,r,x;
    s[0]=-1;
    for (int i=1; i<n;i++)
        if (m[i]==m[i-1]) s[i]=s[i-1];
        else s[i]=i-1;
    for (int i=0;i<M;i++)
    {
        scanf("%d %d %d",&l,&r,&x);
        l--; r--;
        if (m[r]!=x) {r++; printf("%d\n",r);}
        else if (s[r]>=l) {r=s[r]+1; printf("%d\n",r);}
        else printf("%d\n",-1);
    }
    return 0;
}