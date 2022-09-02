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

char ch[1010], ans[1010];
int n, s;

bool dfs(int x, bool tf){
    if(x == n)return tf;
    if(!tf){
        ans[x] = ch[x];
        if(dfs(x+1, 0))return true;
        for(char i=ch[x]+1;i<='a'+s;++i){
            if(x>=1 && i == ans[x-1])continue;
            if(x>=2 && i == ans[x-2])continue;
            ans[x] = i;
            if(dfs(x+1, 1))return true;
        }
        return false;
    }
    else{
        for(char i='a';i<='a'+s;++i){
            if(x>=1 && i == ans[x-1])continue;
            if(x>=2 && i == ans[x-2])continue;
            ans[x] = i;
            if(dfs(x+1, 1))return true;
        }
        return false;
    }
}

int main()
{
    scanf("%d%d",&n,&s);--s;
    scanf("%s",ch);
    for(int i=0;i<n;i++)ans[i] = ch[i];
    if(!dfs(0,0))printf("NO");
    else printf("%s",ans);
    return 0;
}