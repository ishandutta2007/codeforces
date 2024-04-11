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
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N], rel[N];
int main()
{
    int k, n, sum = 0, i;
    cin >> n >>k;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]), sum+=a[i];
    if(sum % k !=0)
        printf("No\n");
    else
    {
        int lim = sum / k, cnt = 0, num = 0;
        //debug(lim);
        for(i=1;i<=n;i++)
        {
            cnt += a[i];
            if(cnt == lim)
            {
                rel[++num] = i;
                cnt = 0;
            }
            else if(cnt > lim)
            {
                printf("No\n");
                return 0;
            }
        }
        printf("Yes\n");
        for(i=1;i<=k;i++)
            printf("%d ", rel[i]-rel[i-1]);
    }
    return 0;
}
// davidlee1999WTK 2018/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/