#include<cstdio>
const int N=100002;
int x[23],T,n,i,j,tmp,Ans;
char s[N],t[N];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%s%s",&n,s,t);
        tmp=1;
        for(i=0;i<20;i++)
            x[i]=0;
        for(i=0;s[i];i++){
            if(s[i]>t[i])
                tmp=0;
            else
                if(s[i]<t[i])
                    x[s[i]-97]|=1<<t[i]-97;
        }
        Ans=0;
        for(i=0;i<20;i++)
            if(x[i]){
                Ans++;
                for(j=i+1;j<20;j++)
                    if(x[i]>>j&1){
                        x[j]|=x[i]^1<<j;
                        break;
                    }
            }
        printf("%d\n",tmp?Ans:-1);
    }
}