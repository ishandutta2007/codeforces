#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,p[maxn],u;
char s[3][maxn],r[maxn],a[maxn];
int solve(int x,int y,int z){
    u=x;
    while(u%25!=y||u%23!=z){
        u+=26;
    }
    return u;
}

int main(){
    scanf("%s",r);
    n=strlen(r);
    printf("? ");
    for(int i=0;i<n;i++)
    printf("%c",i%26+'a');
    printf("\n");
    fflush(stdout);
    scanf("%s",s[0]);
    printf("? ");
    for(int i=0;i<n;i++)
    printf("%c",i%25+'a');
    printf("\n");
    fflush(stdout);
    scanf("%s",s[1]);
    printf("? ");
    for(int i=0;i<n;i++)
    printf("%c",i%23+'a');
    printf("\n");
    fflush(stdout);
    scanf("%s",s[2]);
    for(int i=0;i<n;i++){
        p[i]=solve(s[0][i]-'a',s[1][i]-'a',s[2][i]-'a');
        a[p[i]]=r[i];
    }
    printf("! ");
        printf("%s",a);
}