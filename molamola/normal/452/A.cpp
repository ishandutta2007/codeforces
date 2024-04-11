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

char ch[10][10] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
char inp[10];

int main()
{
    int n, i;
    scanf("%d%s",&n,inp);
    for(i=0;i<8;i++){
        int j;
        for(j=0;ch[i][j];j++);
        if(j != n)continue;
        for(j=0;inp[j];j++)if(inp[j] != '.' && inp[j] != ch[i][j])break;
        if(inp[j])continue;
        printf("%s",ch[i]);
        break;
    }
    return 0;
}