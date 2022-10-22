#include<bits/stdc++.h>
#define maxn 500001
using namespace std;
int nim[maxn];
bool vis[maxn];
int t;
int n;
char s[maxn];
int main() {
    scanf("%d",&t);
    nim[0]=nim[1]=0;
    for(int i=2;i<maxn;i++) {
        for(int j=0;j<=50;j++) vis[j]=false;
        for(int k=0;k+2<=i && k<=100;k++) {
            vis[nim[k]^nim[i-k-2]]=true;
        }
        while(vis[nim[i]]) nim[i]++;
    }
    while(t--) {
        scanf("%d",&n);
        scanf("%s",s);
        int dif=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='B') dif++;
            else dif--;
        }
        if(dif>0) printf("Bob\n");
        else {
            if(dif<0) printf("Alice\n");
            else {
                int cur=0;
                int len=1;
                for(int i=1;i<n;i++) {
                    if(s[i]==s[i-1]) {
                        cur=cur^nim[len];
                        len=1;
                    }
                    else {
                        len++;
                    }
                }
                cur=cur^nim[len];
                if(cur==0) printf("Bob\n");
                else printf("Alice\n");
            }
        }
    }
    return 0;
}