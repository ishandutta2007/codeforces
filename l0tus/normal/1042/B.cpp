#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c[1010],type[7];
    for(int i=0; i<7;i++) type[i]=500010;
    char str[10];
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> c[i] >> str;
        if(strlen(str)==1)
        {
            if(str[0]=='A') type[0] = min(type[0],c[i]);
            if(str[0]=='B') type[1] = min(type[1],c[i]);
            if(str[0]=='C') type[2] = min(type[2],c[i]);
        }
        if(strlen(str)==2)
        {
            if(str[0]+str[1] == 'A'+'B') type[3] = min(type[3],c[i]);
            if(str[0]+str[1] == 'A'+'C') type[4] = min(type[4],c[i]);
            if(str[0]+str[1] == 'B'+'C') type[5] = min(type[5],c[i]);
        }
        if(strlen(str)==3) type[6] = min(type[6],c[i]);
    }
    type[0] = min(type[0],min(type[3],type[4]));
    type[1] = min(type[1],min(type[3],type[5]));
    type[2] = min(type[2],min(type[5],type[4]));
    int ans = min(type[6],min(type[5]+type[0],min(type[4]+type[1],min(type[0]+type[1]+type[2],type[2]+type[3]))));
    if(ans>=500010) cout << -1;
    else cout << ans;
}