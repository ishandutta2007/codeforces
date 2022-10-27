#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,f[11];
char s[maxn];

int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=9;i++)
        scanf("%d",&f[i]);
        bool flag=false;
    for(int i=1;i<=n;i++){
        if(flag&&f[s[i]-'0']<s[i]-'0'){
            break;
        }
        if(f[s[i]-'0']>s[i]-'0'){
            flag=true;
            s[i]=f[s[i]-'0']+'0';
            continue;
        }
    }
    printf("%s\n",s+1);

}