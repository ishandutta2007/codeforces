#include <cstdio>
#include <cstring>

int n;
char s[100005];
int b[100005];
bool q[100005];
int r[100005];


void brd(){
    int i=1,j=0;
    b[0]=0;
    while(i<n){
        while(j&&s[i]!=s[j])j=b[j-1];
        if(s[i]==s[j])j++;
        b[i++]=j;
    }
}

int main(){
    int i;
    scanf("%s",s);
    n=strlen(s);
    brd();
    for(i=0;i<=n;++i){
        r[i]=1;
    }
    for(i=n;i>0;--i){
        r[b[i-1]]+=r[i];
    }
    int k=b[n-1],h=0;
    while(k!=0){
        q[k]=true;h++;
        k=b[k-1];
    }
    q[n]=true;h++;
    printf("%d\n",h);
    for(i=1;i<=n;++i){
        if(q[i])
            printf("%d %d\n",i,r[i]);
    }
    return 0;
}