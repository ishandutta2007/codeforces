#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int ma,mi,n,id1,id2;
char s[maxn],b[maxn];

int main(){
    mi='z'+1;
    scanf("%d%s",&n,s+1);
    for(int i=1;i<n;i++){
        if(s[i]>s[i+1]){
            printf("YES\n");
            printf("%d %d",i,i+1);
            return 0;
        }
    }
    printf("NO");
    return 0;
}
/*
Lucina
*/