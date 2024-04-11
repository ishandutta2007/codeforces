#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int chk[256],n;
char s[1010],t[1010];
int main(){
    chk['a']=chk['e']=chk['i']=chk['o']=chk['u']=1;
    scanf("%s %s",s,t);
    if(strlen(t) != strlen(s)) return !printf("No");
    n=strlen(s);
    for(int i=0;i<n;i++) if(chk[s[i]]!=chk[t[i]]) return !printf("No");
    printf("Yes");
}