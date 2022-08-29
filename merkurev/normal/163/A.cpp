#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

char s[5005],t[5005];

long long numendhere[5005];

long long inf = 1000000007;


int main () {
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    scanf("%s",s);
    scanf("%s",t);

    int slen=strlen(s);
    int tlen=strlen(t);

    long long ans=0;
    long long curcan;

    for (int i=0;i<=slen;i++)
    {
        curcan=1;
        for (int j=0;j<tlen;j++)
        {
            long long vsp = curcan;
            curcan+=numendhere[j];
            curcan%=inf;
            if (t[j]==s[i])
                numendhere[j]=vsp;
            else
                numendhere[j]=0;
        }
        ans+=(curcan-1);
        ans%=inf;
    }
    printf("%I64d",ans);


    return 0;
}