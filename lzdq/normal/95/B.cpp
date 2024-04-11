#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
int n,m;
char s[MAXN],t[MAXN];
bool Auto(int w){
    //printf("Auto %d\n",w);
    int c4=m;
    for(int i=1; i<w; i++)
        c4-=(t[i]==4);
    for(int i=w; i<=m*2; i++){
        if(c4) t[i]=4,c4--;
        else t[i]=7;
    }
    return 1;
}
bool Check(){
    if(n&1) return Auto(1);
    int c4=m,c7=m;
    for(int i=1; i<=n; i++){
        if(s[i]<4) return Auto(i);
        if(s[i]==4){
            if(c4) t[i]=4,c4--;
            else return Auto(i);
        }
        if(s[i]==5||s[i]==6){
            if(c7) return t[i]=7,Auto(i+1);
            while(i&&(s[i]!=4||!c7)) c7+=(s[i--]==7);
            if(!i) return 0;
            t[i]=7;
            return Auto(i+1);
        }
        if(s[i]==7){
            if(c7) t[i]=7,c7--;
            else{
                i--;
                while(i&&(s[i]!=4||!c7)) c7+=(s[i--]==7);
                if(!i) return 0;
                t[i]=7;
                return Auto(i+1);
            }
        }
        if(s[i]>7){
            while(i&&(s[i]!=4||!c7)) c7+=(s[i--]==7);
            if(!i) return 0;
            t[i]=7;
            return Auto(i+1);
        }
    }
    return 1;
}
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    while(scanf("%s",s+1)!=EOF){
        n=strlen(s+1);
        for(int i=1; i<=n; i++)
            s[i]-='0';
        m=n+1>>1;
        if(!Check()) m++,Auto(1);
        for(int i=1; i<=m*2; i++)
            t[i]+='0';
        t[m*2+1]=0;
        puts(t+1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}