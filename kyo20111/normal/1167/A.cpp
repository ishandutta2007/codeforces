#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
char s[111];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        int fl=0;
        for(int i=1;i<=n-10;i++) if(s[i] == '8') fl=1;
        printf("%s\n",(fl?"YES":"NO"));
    }
}