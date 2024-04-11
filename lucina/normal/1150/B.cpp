#include<bits/stdc++.h>
using namespace std;
char s[52][52];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(s[i][j]=='.'&&s[i-1][j]=='.'&&s[i][j-1]=='.'&&s[i][j+1]=='.'&&s[i+1][j]=='.'){

        s[i][j]='#',s[i-1][j]='#',s[i][j-1]='#',s[i][j+1]='#',s[i+1][j]='#';
        }
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(s[i][j]=='.')return printf("NO"),0;
    printf("YES");

}