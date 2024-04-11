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

char h[25],a[25];
int n;
int t,no;
char ha[3],yr[3];
int card[2][105];

void init(void)
{
    memset(card,0,sizeof card);
    scanf("%s%s",h,a);
    scanf("%d",&n);
}

void process(void)
{
    f(i,n)
    {
        scanf("%d%s%d%s",&t,ha,&no,yr);
        if(yr[0]=='r') {if(ha[0]=='h'&&card[0][no]<2) {card[0][no]+=2;printf("%s %d %d\n",h,no,t);}else if(ha[0]=='a'&&card[1][no]<2) {card[1][no]+=2;printf("%s %d %d\n",a,no,t);}}
        else
        {
            if(ha[0]=='h')
            {
                card[0][no]++;
                if(card[0][no]==2) printf("%s %d %d\n",h,no,t);
            }
            else
            {
                card[1][no]++;
                if(card[1][no]==2) printf("%s %d %d\n",a,no,t);
            }
        }
    }
}

int main(void)
{
    init();
    process();
    return 0;
}