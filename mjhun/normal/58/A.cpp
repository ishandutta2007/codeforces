#include <cstdio>
#include <cstring>

char *s = "hello";

int main(){
    char c;
    int i=0, n=strlen(s);
    while((c=getchar())!=EOF&&i<n){
        if(c==s[i])i++;
    }
    if(i==n)puts("YES");
    else puts("NO");
    return 0;
}