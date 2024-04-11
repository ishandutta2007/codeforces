#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,cnt[256];
char a[111],b[111],c[111];
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i='a';i<='z';i++) cnt[i]=0;
        scanf("%s %s %s",a,b,c);
        int r=0;
        for(int i=0;b[i];i++){
            if(b[i] == a[r]) r++;
            else cnt[b[i]]++;
        }
        if(a[r]){
            printf("NO\n");
            continue;
        }
        for(int i=0;c[i];i++) cnt[c[i]]--;
        int fl=0;
        for(int i='a';i<='z';i++) if(cnt[i] > 0) fl=1;
        printf("%s\n",(fl?"NO":"YES"));
    }
}