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

int inp[110];
bool chk[110];

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)scanf("%d",inp+i);
    sort(inp,inp+n);
    int cnt = 0;
    for(i=0;i<n;i++){
        if(chk[i])continue;
        for(int j=0;;j++){
            int t = lower_bound(inp,inp+n,j) - inp;
            while(chk[t])t++;
            if(t == n)break;
            chk[t] = 1;
        }
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}