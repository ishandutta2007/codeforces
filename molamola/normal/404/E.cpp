#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

char ch[1000010];
int p[1000010], n;

bool chk(int x)
{
    int i, mn=0, nw=0;
    for(i=1;i<=n;i++){
        mn = min(mn, nw), nw += p[i], nw = min(nw, x);
    }
    return nw<mn;
}

int main()
{
    scanf("%s",ch+1);
    int i;
    n = strlen(ch+1);
    if(ch[n] == 'R'){
        for(i=1;i<=n;i++)p[i] = (ch[i] == 'R'?-1:1);
    }
    else{
        for(i=1;i<=n;i++)p[i] = (ch[i] != 'R'?-1:1);
    }
    int low = 0, high = n, mid = 0, ans = -1;
    while(low <= high){
        mid = (low + high) / 2;
        if(chk(mid))ans = mid, low = mid + 1;
        else high = mid - 1;
    }
    printf("%d",ans==n?1:ans+1);
    return 0;
}