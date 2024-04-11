#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
char s[300];

int main(){
    scanf("%d %s",&n,s+1);
    int g=0;
    printf("\n");
    for(int i=1;g+i<=n;i++){
            g+=i;
            printf("%c",s[g]);
        }
}