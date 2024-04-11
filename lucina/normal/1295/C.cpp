#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
char s[nax], t[nax];
int n, nxt[nax][26];
bool has[26], h[26];
int solve(){
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    fill(has, has + 26, false);
    fill(h , h + 26 , false);
    for(int i = 1 ; t[i] != '\0' ; i ++){
        has[t[i] - 'a'] = true;
    }
    for(int i = 1 ; s[i] != '\0' ; i ++){
        h[s[i] - 'a'] = true;
    }
    for(int i = 0; i < 26 ; i ++){
        if(has[i] && (!h[i])){
            return  -1;
        }
    }
    int n = strlen(s + 1);
    for(int i = 1 ;i <= n ;i ++){
        for(int j = 0 ;j < 26 ;j ++){
            nxt[i][j] = -1;
        }
    }
    int last[26];
    fill(last, last + 26, -1);
    for(int i = n; i >= 0 ; i --){
        for(int j = 0 ; j < 26 ; j ++){
            if(last[j] != -1){
                nxt[i][j] = last[j];
            }
        }
        if(i > 0)
        last[s[i] - 'a'] = i;
    }
    int ans = 0;
    int cur = 1;
    int m = strlen(t + 1);
    while(cur <= m){
        int v = 0;
        while(cur <= m){
            int now = t[cur] - 'a';
            if(nxt[v][now] == -1) break;
            v = nxt[v][now];
            cur ++ ;
        }
        ans ++ ;
    }
    return ans;
}

int main(){
    int T;
    for(cin >> T ; T -- ;){
        printf("%d\n", solve());
    }
}
/*
    Good Luck
        -Lucina
*/