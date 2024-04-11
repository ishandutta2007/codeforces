#include <cstdio>
#include <cstring>
using namespace std;
char S[100010],T[100010];
int lenT,lenS,i,s[26],t[26],k,ans;
bool flag;
int main() {
    scanf("%s",&S);
    scanf("%s",&T);
    lenT=strlen(T);
    for (i=0;i<lenT;i++) t[T[i]-'a']++;
    lenS=strlen(S);
    for (i=0;i<lenS;i++) {
        if (S[i]!='?') s[S[i]-'a']++;
        if (i>=lenT && S[i-lenT]!='?') s[S[i-lenT]-'a']--;
        if (i>=lenT-1) for (k=0,flag=1;k<26;k++) if (s[k]>t[k]) {flag=0;break;}
        ans+=flag;
    }
    printf("%d",ans);
}