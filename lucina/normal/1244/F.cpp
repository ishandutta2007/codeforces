#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e5+10;

int n, k, start;
char s[maxn];
bool st[maxn], any = true;  //static
vector<int> go;

void compress(){
    int cur = start;
    go.push_back(s[start] == 'B' ? -1 : -2);
    while(cur <= 2 * n && s[cur] == s[start]) cur ++;
    while(cur <= 2 * n){
        if(s[cur] == s[cur + 1]){
            go.push_back(s[cur] == 'B' ? -1 : -2);
            while(s[cur] == s[cur + 1] && cur <= 2 *n)
                cur ++;
            cur ++ ;
        }
        else go.push_back(cur++);
    }
}
void Fuck(){
    int m = go.size() ;
    for(int  i = 0 ; i < m ; i++){
        if(go[i] < 0){
            int j = i + 1;
            while(j < m && go[j] >= 0)
                j ++;
            if(j == i + 1 || j == m){
                continue;
            }
            int l = go[i + 1] , r = go[j - 1];
            if(l < 0 || r < 0)continue;
            int len  = r - l + 1;
            if(go[i] == go[j]){
                if(k * 2 >= len){
                    for(int x = l ; x <= r ; x++)
                        s[x] = (go[i] == -1)? 'B' : 'W';
                }
                else{
                for(int x = l ; x < l + k ; x++)
                    s[x] = (go[i] == -1) ? 'B' : 'W';
                for(int x = r ;x > r - k; x--)
                    s[x] = (go[i] == -1) ? 'B' : 'W';
                for(int x = l + k ; x <= r- k ; x++)
                    s[x] = s[x-1] == 'B' ? 'W' : 'B';
                }
            }
            else{
                if(k * 2 <= len){
                    for(int x = l, y = r , stp = 0; stp < k; stp++, x++, y--){
                        s[x] = (go[i] == -1) ? 'B' : 'W';
                        s[y] = (go[j] == -1) ? 'B' : 'W';
                    }
                    for(int x = l + k ; x <= r - k ; x++)
                        s[x] = (s[x-1] == 'B') ? 'W' : 'B';
                }
                else {
                    for(int x = l , y = r; x < y ; x++ , y --){
                        s[x] = (go[i] == -1) ? 'B' : 'W';
                        s[y] = (go[j] == -1) ? 'B' : 'W';
                    }
                }
            }
        }
    }
}

void printshitanswer(){
    string t1;
    int i, ct = 0;
    for( i = start ; i % n != 1 ; i++, ct ++)
        t1 += s[i];
    for(int x = 0 ; x < (n - ct) ; x ++ )
        printf("%c", s[i + x]);
    printf("%s", t1.c_str());
}

int main(){
    scanf("%d %d",&n,&k);
    scanf("%s" , s + 1);
    s[n + 1] = s[1];
    s[0] = s[n];
    for(int i = n + 1 ; i<= 2 * n ; i++){
        s[i] = s[i - n];
    }
    s[2 * n + 1] = s[1];
    for(int i = 1 ;i <= 2 * n; i++){
        if(s[i] == s[i + 1] || s[i] == s[i-1]){
            st[i] = true;
            any = false;
        }
    }
    st[0] = st[n];
    if(any){
        k &= 1;
        for(int i = 1 ;i <= n;i ++){
            printf("%c" , k ^ (s[i] == 'B') ? 'B' : 'W');
        }
        return 0;
    }
    while(!st[start]) start ++;
    compress();
    Fuck();
    printshitanswer();
}
/*
    Virtual Round 592
*/