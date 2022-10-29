#include <cstdio>
#include <iostream>
using namespace std;

char s[1024];
int freq[256];
int k;
char s2[1024];

int main(){
    int i,j;
    scanf("%d",&k);
    scanf("%s",s);
    i=0;
    while(s[i]){
        freq[s[i++]]++;//
    }
    bool r=true;
    for(i=0;i<256;++i){
        if(freq[s[i]]%k)r=false;
    }
    if(!r){
        puts("-1");
    }
    else {
        int c=0;
        for(i=0;i<256;++i){
            if(freq[i]){
                int q=freq[i]/k;
                for(j=c;j<q+c;++j){
                    s2[j]=i;
                }
                c+=q;
            }
        }
        s2[c]=0;
        for(i=0;i<k;++i){
            printf("%s",s2);
        }
        putchar('\n');
    }
    return 0;
}