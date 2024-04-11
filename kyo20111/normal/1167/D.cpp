#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,st,ans[202020];
char s[202020];
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);

    for(int i=1;i<=n;i++){
        if(s[i] == '('){
            st++;
            ans[i] = st%2;
        }else{
            ans[i] = st%2;
            st--;
        }
    }
    for(int i=1;i<=n;i++) printf("%d",ans[i]);
}