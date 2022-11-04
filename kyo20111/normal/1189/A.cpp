#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[256];
char s[111];
int main(){
    scanf("%*d %s",s);
    for(int i=0;s[i];i++) cnt[s[i]]++;
    if(cnt['0']==cnt['1']){
        printf("2\n%c %s",s[0],s+1);
    }else printf("1\n%s",s);
}