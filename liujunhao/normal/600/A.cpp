#include<cstdio>
#include<cstring>
#define MAXN 100000
char s[MAXN+10],a[MAXN+10],b[MAXN+10];
int n,an,bn;
int main()
{
    int i,j;
    scanf("%s",s);
    n=strlen(s);
    bool f;
    for(i=-1;i<n;){
        f=0;
        for(j=i+1;s[j]!=';'&&s[j]!=','&&s[j];j++)
            if(s[j]<'0'||s[j]>'9')
                f=1;
        if(j-i==1||f||(j-i>2&&s[i+1]=='0')){
            for(i++;i<j;i++)
                b[bn++]=s[i];
            b[bn++]=',';
        }
        else{
            for(i++;i<j;i++)
                a[an++]=s[i];
            a[an++]=',';
        }
    }
    if(!an)
        puts("-");
    else{
        a[an-1]=0;
        printf("\"%s\"\n",a);
    }
    if(!bn)
        puts("-");
    else{
        b[bn-1]=0;
        printf("\"%s\"\n",b);
    }
}