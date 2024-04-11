#include<bits/stdc++.h>
using namespace std;
char s[2000000];
int n;
long long dv=0;
long long o=0;
long long r=0;
int main() {
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i+1<n;i++) {
        if(s[i]=='v' && s[i+1]=='v') {
            r+=o;
            dv++;
        }
        if(s[i]=='o') {
            o+=dv;
        }
    }
    printf("%lld",r);
    return 0;
}