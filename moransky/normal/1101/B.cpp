#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 500010;
int n;
char s[N];
int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int l = 1, r = n, cnt = 0;
    while(l <= n && s[l] != '[') l++;
    while(r && s[r] != ']') r--;
    while(l <= n && s[l] != ':') l++;
    while(r && s[r] != ':') r--;
    if(l >= r) puts("-1");
    else{
        for(int i = l; i <= r; i++)
            if(s[i] == '|') cnt++;
        printf("%d\n", 4 + cnt);
    }
    
    
    return 0;
}