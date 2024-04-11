#include<bits/stdc++.h>
using namespace std;
int n,a[26],ans;
char s[26];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        a[s[0]-'a']++;
    }
    for(int i=0;i<26;i++){
        n=(a[i]>>1);
        ans+=(((a[i]-n-1)*(a[i]-n))+(n*(n-1)));
    }
    ans>>=1;
    printf("%d\n",ans);
}