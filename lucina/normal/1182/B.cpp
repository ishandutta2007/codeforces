
 #include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m;
char s[510][510];

int main(){

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
        int ct=0;
    for(int i=0;i<=505;i++)
        for(int j=0;j<=505;j++)
        if(s[i][j]!='*'&&s[i][j]!='.')
        s[i][j]='.';
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(s[i][j]=='*')ct++;
        if(ct==0)return !printf("NO");
        ct=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(s[i][j]=='*'&&ct==0){
            char x='*';
            if(s[i][j-1]==x&&s[i-1][j]==x&&s[i+1][j]==x&&s[i][j+1]==x){
                ct++;
                for(int k=j+1;s[i][k]=='*';k++)
                    s[i][k]='.';
                for(int k=j-1;s[i][k]=='*';k--)
                    s[i][k]='.';
                for(int k=i+1;s[k][j]=='*';k++)
                    s[k][j]='.';
                for(int k=i-1;s[k][j]=='*';k--)
                    s[k][j]='.';
                s[i][j]='.';
            }
        }
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(s[i][j]=='*')
        return !printf("NO");
    printf("YES");
}