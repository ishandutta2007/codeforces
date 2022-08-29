#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int main()
{

    int n;
    scanf("%d",&n);
    char a[1005];
    char b[1005];
    scanf("%s",a);
    scanf("%s",b);
    int la=strlen(a);
    int lb=strlen(b);
    pair<int,int> ans=make_pair(0,0),curans=make_pair(0,0);
    for (int i=0;i<la*lb;i++)
    {
        
        if (i==n%(la*lb))
            ans=curans;
        char ca=a[i%la];
        char cb=b[i%lb];
        if (ca=='R')
        {
            if (cb=='S')
                curans.first++;
            else if (cb=='P')
                curans.second++;
        }
        else if (ca=='S')
        {
            if (cb=='P')
                curans.first++;
            else if (cb=='R')
                curans.second++;
        }
        else if (ca=='P')
        {
            if (cb=='R')
                curans.first++;
            else if (cb=='S')
                curans.second++;
        }
    }
    ans.first+=curans.first*(n/(la*lb));
    ans.second+=curans.second*(n/(la*lb));
    
    printf("%d %d",ans.second,ans.first);

    return 0;
}