#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n1,n2;
char s1[1010101],s2[1010101];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf(" %s %s",s1,s2);
        n1 = strlen(s1);
        n2 = strlen(s2);
        if(n1 > n2){
            printf("NO\n");
            continue;
        }

        int l=0,fl=0;
        for(int i=0;i<n1;i++){
            if(s1[i] != s2[l]){
                fl=1;
                break;
            }

            if(s1[i] == s1[i+1]){
                l++;
                continue;
            }

            while(l < n2 && s1[i] == s2[l]){
                l++;
            }
        }
        printf("%s\n",(fl||l!=n2)?"NO":"YES");
    }
}