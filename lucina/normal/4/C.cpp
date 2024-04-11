#include<bits/stdc++.h>
using namespace std;
unordered_map <string,int>fuck;
char s[42];
int n;
int main(){
    string g;
    fuck.reserve(131072);
    fuck.max_load_factor(0.25);
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        g=string(s);
        if(fuck[g]==0){
            printf("OK\n");
        }
        else{
            printf("%s",s);
            printf("%d\n",fuck[g]);}
        fuck[g]++;
    }
}