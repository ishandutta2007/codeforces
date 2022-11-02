#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define For(i,n) for(i=0;i<(n);i++)

int s[1010],ans[1010],n,p;
bool g=true;

void inc(int m){
    int i,t;
    ans[m]=(ans[m]+1)%p;
    while((ans[m]==ans[m-1]||ans[m]==ans[m-2])&&ans[m]!=0){
        ans[m]=(ans[m]+1)%p;
    }
    if(ans[m]==0){
        if(m!=2){
            inc(m-1);
        }
        else{
            g=false;
            return;
        }
    }
    else{
        if(ans[m-1]==0){
            if(ans[m]==1){
                t=2;
                for(i=m+1;i<n+2;i++){
                    ans[i]=t%3;
                    t++;
                }
                return;
            }
            t=1000000000;
            for(i=m+1;i<n+2;i++){
                ans[i]=t%3;
                t--;
            }
            return;
        }
        if(ans[m-1]==1){
            if(ans[m]==0){
                t=1000000001;
                for(i=m+1;i<n+2;i++){
                    ans[i]=t%3;
                    t--;
                }
                return;
            }
            t=0;
            for(i=m+1;i<n+2;i++){
                ans[i]=t%3;
                t++;
            }
            return;
        }
        if(ans[m-1]==2){
            if(ans[m]==0){
                t=1;
                for(i=m+1;i<n+2;i++){
                    ans[i]=t%3;
                    t++;
                }
                return;
            }
            if(ans[m]==1){
                t=999999999;
                for(i=m+1;i<n+2;i++){
                    ans[i]=t%3;
                    t--;
                }
                return;
            }
        }
        if(ans[m]==0){
            t=1;
            for(i=m+1;i<n+2;i++){
                ans[i]=t%3;
                t++;
            }
            return;
        }
        if(ans[m]==1){
            t=999999999;
            for(i=m+1;i<n+2;i++){
                ans[i]=t%3;
                t--;
            }
            return;
        }
        t=0;
        for(i=m+1;i<n+2;i++){
            ans[i]=t%3;
            t++;
        }
        return;
    }
}

void solve(){
    char c;
    int i;
    scanf("%c",&c);
    ans[0]=-1;
    ans[1]=-1;
    For(i,n){
        scanf("%c",&c);
        s[i+2]=c-'a';
        ans[i+2]=c-'a';
    }
    inc(n+1);
    i=2;
//  while(ans[i]==s[i]&&i<n) i++;
//  if(i==n) g=false;
//  else if(ans[i]<s[i]) g=false;
    if(g){
        For(i,n) printf("%c",(char)(ans[i+2]+(int)'a'));
    }
    else printf("NO");
}

int main() {
#pragma comment(linker, "/STACK:67108864")
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
    while(scanf("%d%d",&n,&p)!=EOF){
    solve();
    }
    return 0;
}