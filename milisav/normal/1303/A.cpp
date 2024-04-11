#include<bits/stdc++.h>
using namespace std;
char s[1000];
int t;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%s",s);
        int n=strlen(s);
        bool beg=false;
        int cl=0;
        int ans=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='0') cl++;
            else {
                if(beg) ans+=cl;
                cl=0;
                beg=true;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}