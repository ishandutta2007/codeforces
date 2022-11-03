#include <cstdio>
#include <cstring>
const int maxn=100005;
const char f0[]="What are you doing at the end of the world? Are you busy? Will you save us?";
const char fi1[]="What are you doing while sending \"";
const char fi2[]="\"? Are you busy? Will you send \"";
const char fi3[]="\"?";
const int f0len=strlen(f0);
const int fi1len=strlen(fi1);
const int fi2len=strlen(fi2);
const int fi3len=strlen(fi3);
long long len[maxn];
int main()
{
    int i=1,q,n; len[0]=f0len;
    long long k;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%I64d",&n,&k);
        for(;i<=n;i++)
            if(len[i-1]==-1)
                len[i]=-1;
            else
            {
                len[i]=len[i-1]*2+fi1len+fi2len+fi3len;
                if(len[i]>1e18)
                    len[i]=-1;
            }
        for(;n;n--)
            if(k<=fi1len)
            {
                printf("%c",fi1[k-1]);
                break;
            }
            else if(k<=fi1len+len[n-1] || len[n-1]==-1)
                k-=fi1len;
            else if(k<=fi1len+len[n-1]+fi2len)
            {
                printf("%c",fi2[k-fi1len-len[n-1]-1]);
                break;
            }
            else if(k<=fi1len+len[n-1]+fi2len+len[n-1])
                k-=fi1len+len[n-1]+fi2len;
            else if(k<=fi1len+len[n-1]+fi2len+len[n-1]+fi3len)
            {
                printf("%c",fi3[k-fi1len-len[n-1]-fi2len-len[n-1]-1]);
                break;
            }
            else
            {
                printf(".");
                break;
            }
        if(!n) printf("%c",(k<=f0len)?f0[k-1]:'.');
    }
    printf("\n");
    return 0;
}