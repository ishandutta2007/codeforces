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

int d[1000010][5];
char ch[1000010];

const int M = 1e9 + 7;

int main()
{
    int n;
    scanf("%s",ch+1);
    n = strlen(ch+1);
    int i;
    if(ch[1] == '0')d[1][1] = 1;
    else if(ch[1] == '1')d[1][3] = 1;
    else if(ch[1] == '2'){
        printf("0");return 0;
    }
    else if(ch[1] == '*')d[1][0] = 1;
    else if(ch[1] == '?')d[1][0] = d[1][1] = d[1][3] = 1;
    for(i=2;i<=n;i++){
        if(ch[i] == '0' || ch[i] == '?'){
            d[i][1] = (d[i-1][1] + d[i-1][2]) % M;
        }
        if(ch[i] == '1' || ch[i] == '?'){
            d[i][2] = d[i-1][0];
            d[i][3] = (d[i-1][1] + d[i-1][2]) % M;
        }
        if(ch[i] == '2' || ch[i] == '?'){
            d[i][4] = d[i-1][0];
        }
        if(ch[i] == '*' || ch[i] == '?'){
            d[i][0] = ((d[i-1][0] + d[i-1][3]) % M + d[i-1][4]) % M;
        }
    }
    int ans = (d[n][0] + d[n][1])%M;
    ans = (ans + d[n][2])%M;
    printf("%d",ans);
    return 0;
}