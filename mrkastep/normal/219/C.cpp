#include <stdio.h>
#include <algorithm>
#include <vector>
#define For(i,n) for(i=0;i<(n);i++)


void solve(int n){
    int k,i,ans=0,t=0,s[500500];
    char c;
    scanf("%d",&k);
    getchar();
    For(i,n){
        c=getchar();
        s[i]=c-'A';
    }
    if(k==2){
        For(i,n){
            t+=s[i]^(i%2);
        }
        if(t<=n/2){
            printf("%d\n",t);
            For(i,n){
                printf("%c",(char)('A'+i%2));
            }
        }
        else{
            printf("%d\n",n-t);
            For(i,n){
                printf("%c",(char)('A'+(i+1)%2));
            }
        }
        return;
    }
    for(i=1;i<n-1;i++){
        if(s[i]==s[i-1]){
            ans++;
            s[i]=0;
            while(s[i]==s[i-1]||s[i]==s[i+1]) s[i]++;
            i++;
        }
        if(i==n-2){
            if(s[i]==s[i+1]){
                ans++;
                s[i]=0;
                while(s[i]==s[i-1]||s[i]==s[i+1]) s[i]++;
                i++;
            }
        }
    }
    if(n==2&&s[0]==s[1]){
        s[0]++;
        s[0]%=k;
        ans++;
    }
    printf("%d\n",ans);
    For(i,n){
        printf("%c",(char)('A'+s[i]));
    }
}

int main() {
#pragma comment(linker, "/STACK:67108864") 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    while(scanf("%d",&n)!=EOF){
    solve(n);
    }
    return 0;
}