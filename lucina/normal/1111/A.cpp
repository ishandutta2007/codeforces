#include<bits/stdc++.h>
using namespace std;
char a[2005],b[2005];
int c1,c2,n,m;

int main(){
    scanf("%s %s",a,b);
    n=strlen(a);
    m=strlen(b);
    if(n!=m){
        printf("No");
        return 0;
    }
    
    for(int i=0;i<n;i++){
        c1=0,c2=0;
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
            c1=1;
        if(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u')
            c2=1;
        if(c1!=c2){
        printf("No");
        return 0;
        }
    }
    printf("Yes");
}