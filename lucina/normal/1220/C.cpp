#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
char s[maxn];

int main(){
    scanf("%s",s+1);
    int mi = 10000;
    for(int i=1;s[i] != '\0' ;i++){
        printf(s[i]- 'a' + 1 <= mi ? "Mike\n" : "Ann\n");
        mi = min(s[i]-'a' + 1, mi);
    }
}