#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=205;
int T;
char s[N],t[N];
void sol(char s[]){
    scanf("%s",s+1);int n=strlen(s+1);
    int top=0,cnt=0;
    rep(i,n)if(s[i]=='B')++cnt;
        else if(top>0&&s[top]==s[i])--top;
        else s[++top]=s[i];
    if(cnt%2==1)s[++top]='B';
    s[++top]='\0';
}
int main() {
    for(scanf("%d",&T);T--;){
        sol(s);sol(t);
        puts(strcmp(s+1,t+1)==0?"YES":"NO");
    }

}