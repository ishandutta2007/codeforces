#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[2],len[55];
char s[55];
int main(){
    scanf("%d",&t);
    while(t--){
        cnt[0] = cnt[1] = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            len[i] = strlen(s);
            for(int j=0;s[j];j++) cnt[s[j]-'0']++;
        }
        sort(len+1, len+1+n);
        int ans = 0;
        while(ans++ < n){
            int fl=0;
            for(int i=2;i<=len[ans];i+=2){
                if(cnt[0] >= 2) cnt[0] -= 2;
                else if(cnt[1] >= 2) cnt[1] -= 2;
                else{
                    fl=1;
                    break;
                }
            }
            if(len[ans]%2){
                if(cnt[0] && cnt[0] % 2) cnt[0]--;
                else if(cnt[1] && cnt[1] % 2) cnt[1]--;
                else if(cnt[0]) cnt[0]--;
                else if(cnt[1]) cnt[1]--;
                else fl = 1;
            }
            if(fl) break;
        }
        printf("%d\n",ans-1);
    }
}