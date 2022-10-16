#include<bits/stdc++.h>
#define f(i,n) for(int i=1;i<=n;i++)
#define F(i,n) for(int i=n;i>=1;i--)
#define FF(i,a,b) for(int i=a;i>=b;i--)
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define fi first
#define se second
#define B 1
#define W -1
typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5;
const ll mod=1e9+7,INF=1<<30;

char s[1000005];
ll a,b;

ll pwr(ll a,ll e)
{
    ll mult=a,res=1,d=e;
    while(d)
    {
        if(d&1) res=(res*mult)%b;
        mult=(mult*mult)%b;
        d>>=1;
    }
    return res;
}

void init(void)
{
    scanf("%s",s);
    scanf("%I64d%I64d",&a,&b);
}

void process(void)
{
    ll pos=0,len=strlen(s),resa=s[0]-'0',resb=0;
    if(len==1) {printf("NO");return;}
    resa%=a;
    f(i,len-1) {int tmp=s[i]-'0';resb=(resb+tmp*pwr(10,len-1-i))%b;}
    if(resa==0&&resb==0&&s[1]!='0')
    {
        printf("YES\n%c\n",s[0]);
        f(i,len-1) printf("%c",s[i]);
        return;
    }
    f(i,len-1)
    {
        int tmp=s[i]-'0';
        if(resa==0&&resb==0&&tmp!=0)
        {
            printf("YES\n");
            ff(j,0,i-1) printf("%c",s[j]);
            printf("\n");
            ff(j,i,len-1) printf("%c",s[j]);
            return;
        }
        resa=(10*resa+tmp)%a;
        resb=(resb-tmp*pwr(10,len-1-i)+b)%b;
    }
    printf("NO");
}

int main(void)
{
    init();
    process();
    return 0;
}