#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,chk[256];
char s[505];
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i='a';i<='z';i++) chk[i] = 0;
        scanf("%s",s);
        int cur = 0, cnt = 0;
        for(int i=0;s[i];i++){
            if(s[i] == cur){
                cnt++;
            }else{
                if(cnt%2) chk[cur] = 1;
                cur = s[i], cnt = 1;
            }
        }
        if(cnt%2) chk[cur] = 1;
        for(int i='a';i<='z';i++) if(chk[i]) printf("%c",i);
        puts("");
    }
}