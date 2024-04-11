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

char ch[330][330];
int n;

bool solve()
{
    int i, j;
    for(i=0;i<n;i++){
        if(ch[i][i] != ch[0][0])return false;
        if(ch[n-1-i][i] != ch[0][0])return false;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i == j || i+j == n-1)continue;
            if(ch[i][j] != ch[1][0])return false;
        }
    }
    return ch[0][0] != ch[1][0];
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",ch[i]);
    printf("%s",solve()?"YES":"NO");
    return 0;
}