#include <stdio.h>
typedef long long ll;
const int maxn=5000005;
const int len=5;
const ll mod[len]={1580181960001ll,1695326802963ll,1516248691946ll,3465898195354ll,9999999999999ll};
const ll base[len]={174,934,159,358,964};
int f[maxn],ans;
ll now[2][len],pow_[len];
char s[maxn];
int main()
{
    int i,j=0;
    bool flag;
    scanf("%s",s+1);
    f[0]=0;
    //for(j=0;j<len;j++)
        now[0][j]=now[1][j]=0,pow_[j]=1;
    for(i=1;s[i];i++)
    {
        flag=true;
        //for(j=0;j<len;j++)
        {
            (now[0][j]=base[j]*now[0][j]+s[i])%=mod[j];
            (now[1][j]=now[1][j]+pow_[j]*s[i])%=mod[j];
            if(now[0][j]!=now[1][j])
                flag=false;
            (pow_[j]*=base[j])%=mod[j];
        }
        if(flag)
            ans+=(f[i]=f[i>>1]+1);
        else
            f[i]=0;
    }
    printf("%d\n",ans);
    return 0;
}