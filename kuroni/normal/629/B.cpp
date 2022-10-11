#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[1];
    int a,b,n,i,ans=0,j,pp[366],bl[366];
    memset(pp,0,sizeof(pp));
    memset(bl,0,sizeof(bl));
    cin>>n;
    for (i=0;i<n;i++)
    {
        scanf("%1s %d %d",&str,&a,&b);
        if (str[0] == 'F') {for (j=a-1;j<b;j++) {bl[j]--; pp[j]++;}} else {for (j=a-1;j<b;j++) {bl[j]++; pp[j]++;}}
    }
    for (i=0;i<366;i++)
    {
        ans = max(ans,pp[i] - abs(bl[i]));
    }
    cout<<ans;
    return 0;
}