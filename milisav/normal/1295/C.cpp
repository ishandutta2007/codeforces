#include<bits/stdc++.h>
using namespace std;
int tc;
char s[2000000];
char t[2000000];
int fst[100005][26];
int ni[26];
int main() {
    scanf("%d",&tc);
    while(tc--) {
        int n,m;
        scanf("%s",s);
        scanf("%s",t);
        n=strlen(s);
        m=strlen(t);
        for(int i=0;i<26;i++) ni[i]=-1;
        for(int i=n-1;i>=0;i--) {
            ni[s[i]-'a']=i;
            for(int j=0;j<26;j++) fst[i][j]=ni[j];
        }
        int ans=0;
        int i=0;
        while(i<m) {
            int j=0;
            ans++;
            if(fst[j][t[i]-'a']==-1) {
                ans=-1;
                break;
            }
            else {
                while(i<m && j!=-1 && j<n) {
                    if(fst[j][t[i]-'a']==-1) break;
                    j=fst[j][t[i]-'a']+1;
                    i++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}