#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1010;
char s[N];
int cnt[26], tot = 0, loc = 0;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        memset(cnt, 0, sizeof cnt); loc = tot = 0;
        bool ep = false;
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        for(int i = 1; i <= n; i++){
            cnt[s[i] - 'a'] ++;
        }
        for(int i = 0; i < 26; i++){
            if(cnt[i]) tot++, loc = i;
        }
        if(tot == 1) puts("-1");
        else{
            for(int i = 1; i <= n; i++)
                if(s[i] == s[n - i + 1] && i != n - i + 1){
                    for(int j = 1; j <= n; j++){
                        if(i != j && j != n - i + 1){
                            if(s[j] != s[i]){
                                swap(s[j], s[i]);
                                printf("%s\n", s + 1);
                                ep = true; break;
                            }
                        } 
                    }
                    if(ep) break;
                }
            if(!ep) printf("%s\n", s + 1);
        }
    }
    return 0;
}