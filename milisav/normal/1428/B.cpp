#include<bits/stdc++.h>
#define maxn 400000
using namespace std;
int t;
int n;
char s[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        scanf("%s",s);
        bool al=false;
        bool pos=true;
        for(int i=0;i<n;i++) if(s[i]=='<') pos=false;
        if(pos) al=true;
        pos=true;
        for(int i=0;i<n;i++) if(s[i]=='>') pos=false;
        if(pos) al=true;
        if(al) printf("%d\n",n);
        else {
            int cnt=0;
            for(int i=0;i<n;i++) {
                int j=(i+1);
                if(j>=n) j-=n;
                if(s[i]=='-' || s[j]=='-') cnt++;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}