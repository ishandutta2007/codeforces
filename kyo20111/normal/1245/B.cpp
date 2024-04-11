#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a,b,c;
char s[111],out[111];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&n,&a,&b,&c);
        scanf("%s",s+1);
        int l = 0;
        for(int i=1;i<=n;i++) out[i] = 0;
        for(int i=1;i<=n;i++){
            if(s[i] == 'S' && a){
                out[i] = 'R';
                a--;
                l++;
            }else if(s[i] == 'R' && b){
                out[i] = 'P';
                b--;
                l++;
            }else if(s[i] == 'P' && c){
                out[i] = 'S';
                c--;
                l++;
            }
        }
        if(l < (n+1)/2){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int i=1;i<=n;i++){
            if(out[i]){
                printf("%c",out[i]);
            }else{
                if(a){
                    printf("R");
                    a--;
                }else if(b){
                    printf("P");
                    b--;
                }else{
                    printf("S");
                    c--;
                }
            }
        }
        puts("");
    }
}