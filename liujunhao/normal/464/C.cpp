#include<cstdio>
#include<string>
#include<cstring>
typedef long long LL;
using namespace std;
#define MAXLEN 100000
#define MOD 1000000007
char s[MAXLEN+10],q[MAXLEN+10];
string que[MAXLEN+10];
int n,a[11],SET[11];
int main()
{
    fgets(s,MAXLEN+10,stdin);
    LL len,i,j,num;
    scanf("%d",&n);
    char c;
    for(i=1;i<=n;i++){
        while(c=getchar(),c<'0'||c>'9');
        q[i]=c;
        while(c=getchar(),c=='-'||c=='>');
        if(c>'9'||c<'0')
            continue;
        que[i]+=c;
        while(c=getchar(),c>='0'&&c<='9')
            que[i]+=c;
    }
    for(i=0;i<10;i++)
        a[i]=i,SET[i]=10;
    LL tmp,set;
    for(i=n;i;i--){
        len=que[i].length();
        tmp=0,set=1;
        for(j=len-1;j>=0;j--){
            num=que[i][j]-'0';
            tmp+=set*a[num]%MOD;
            set=set*SET[num]%MOD;
        }
        a[q[i]-'0']=tmp%MOD;
        SET[q[i]-'0']=set;
    }
    len=strlen(s)-1;
    s[len]=0;
    LL ans = 0;
    set=1;
    for (int i=len-1;i>=0;i--)
    {
        ans=(ans+set*a[s[i]-'0'])%MOD;
        set=set*SET[s[i]-'0']%MOD;
    }
    printf("%I64d",ans);
    return 0;
}