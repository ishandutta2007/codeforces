#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
long long x,y;
char s[maxn];
int t[maxn];
int n;
long long c[2];
long long ans=0;
long long suf[maxn][2];
int main() {
    scanf("%s",s);
    scanf("%lld %lld",&x,&y);
    n=strlen(s);
    for(int i=0;i<n;i++) {
        t[i]=s[i]-'0';
        if(s[i]=='?') {
            if(y<x) t[i]=0;
            else t[i]=1;
        }
    }
    suf[n][0]=suf[n][1]=0;
    for(int i=n-1;i>=0;i--) {
        suf[i][t[i]]=suf[i+1][t[i]]+1;
        suf[i][1-t[i]]=suf[i+1][1-t[i]];
    }
    for(int i=0;i<n;i++) {
        if(t[i]==1) ans=ans+x*c[0];
        else ans=ans+y*c[1];
        c[t[i]]++;
    }
    c[0]=c[1]=0;
    long long cans=ans;
    for(int i=0;i<n;i++) {
        if(s[i]=='?') {
            if(y<x) {
                cans=cans-c[1]*y+c[0]*x-suf[i+1][1]*x+suf[i+1][0]*y;
                t[i]=1;
            }
            else {
                cans=cans-c[0]*x+c[1]*y-suf[i+1][0]*y+suf[i+1][1]*x;
                t[i]=0;
            }
            ans=min(ans,cans);
        }
        c[t[i]]++;
    }
    printf("%lld",ans);
    return 0;
}