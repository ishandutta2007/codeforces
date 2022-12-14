#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 200005
#define P1 1000000007
#define P2 998244353
#define K1 233
#define K2 107
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
map<pii, int> cur;
map<pii, int> num;
char s[10005][11], t[11];
void Insert(char *s, int idx)
{
    int m = strlen(s+1), i, j;
    map<pii, int> mp;
    for(i=1;i<=m;i++)
    {
        int hs1 = 0, hs2 = 0;
        for(j=i;j<=m;j++)
        {
            hs1 = ((LL)hs1 * K1 + s[j]) % P1;
            hs2 = ((LL)hs2 * K2 + s[j]) % P2;
            if(!mp[MP(hs1, hs2)])
            {
                cur[MP(hs1, hs2)]+=1;
                mp[MP(hs1, hs2)]+=1;
                num[MP(hs1, hs2)] = idx;
            }
        }
    }
}
int main()
{
    int n, i, j;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        scanf("%s", s[i]+1);
        Insert(s[i], i);
    }
    int q;
    cin >> q;
    while(q--)
    {
        scanf("%s", t+1);
        int m=strlen(t+1);
        int hs1 = 0, hs2 = 0;
        for(j=1;j<=m;j++)
        {
            hs1 = ((LL)hs1 * K1 + t[j]) % P1;
            hs2 = ((LL)hs2 * K2 + t[j]) % P2;
        }
        pii key = MP(hs1, hs2);
        if(cur[key] == 0)
            printf("0 -\n");
        else
            printf("%d %s\n", cur[key], s[num[key]]+1);
    }
    return 0;
}
// davidlee1999WTK 2018/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/