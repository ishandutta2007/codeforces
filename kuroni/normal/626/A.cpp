#include <bits/stdc++.h>

using namespace std;

main()
{
    char str[200];
    int n, i, pos[400][400],v=200,h=200,ans=0;
    memset(pos,0,(sizeof(pos[0][0])*400*400));
    pos[200][200] = 1;
    cin>>n;
    scanf("%s",&str);
    for (i=0;i<n;i++)
    {
        if (str[i] == 'U') v++;
        if (str[i] == 'D') v--;
        if (str[i] == 'R') h++;
        if (str[i] == 'L') h--;
        ans += pos[v][h];
        pos[v][h]++;
    }
    cout<<ans;
}