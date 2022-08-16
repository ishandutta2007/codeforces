#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int limit[20];

void base_limit()
{
    for (int i=2;i<=16;++i)
    {
        int tmp=1;
        for (int j=1;;++j)
        {
            tmp*=i;
            if (tmp>10000)
            {
                limit[i]=j;
                break;
            }
        }
    }
}

int prime[100];
int MOD[10],L[10],R[10];

void get_prime()
{
    int flag[101]={0};
    for (int i=2;i<=100;++i)
        if (!flag[i])
        {
            prime[++prime[0]]=i;
            for (int j=2;j<=100/i;++j)
                flag[i*j]=1;
        }
    int tot=0;
    for (int i=1;i<=prime[0];++i)
    {
        long long tmp=1;
        int j;
        for (j=i;j<=prime[0];++j)
        {
            tmp*=prime[j];
            if (tmp>2147483647) break;
        }
        ++tot;
        if (tmp>2147483647)
            tmp/=prime[j];
        MOD[tot]=tmp;
        L[tot]=i;
        R[tot]=j-1;
        if (j>prime[0]) break;
        i=j-1;
    }
}

int pow[20][20];

void power()
{
    for (int i=2;i<=18;++i)
    {
        pow[i][0]=1;
        for (int j=1;j<=15;++j)
            pow[i][j]=pow[i][j-1]*i;
    }
}

const int MaxN=10010;
const int MaxM=30010;

int n,m;
long long a[MaxN];
int d[MaxM],mark[MaxM],ans[MaxM];
int s[MaxM][40];
long long c[MaxM];

int p[MaxM];

long long F[5000000];
int b[5000000],T;

bool cmp(int i,int j)
{
    return d[i]<d[j];
}

void init()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%I64d",&a[i]);
    scanf("%d",&m);
    char word[40];
    for (int i=1;i<=m;++i)
    {
        scanf("%d%s%I64d",&d[i],word+1,&c[i]);
        int len=strlen(word+1);
        mark[i]=0;
        int x,y=len;
        for (x=limit[d[i]];x>=1;--x)
        {
            if (word[y]=='?')
                s[i][x]=0;
            else if (word[y]>='0'&&word[y]<='9')
                s[i][x]=word[y]-'0'+1;
            else
                s[i][x]=word[y]-'A'+11;
            --y;
            if (!y) break;
        }
        for (--x;x>=1;--x)
            s[i][x]=1;
        for (x=1;x<=y;++x)
            if (word[x]!='?'&&word[x]!='0')
                mark[i]=1;
        p[i]=i;
    }
    sort(p+1,p+m+1,cmp);
}

long long DP(int now,int num,int MOD)
{
    if (b[num]>=T) return F[num];
    F[num]=1;
    b[num]=T;
    int q[20];
    int i,tmp=num;
    for (i=1;i<=limit[now];++i)
    {
        q[i]=tmp%(now+1);
        tmp/=(now+1);
    }
    int place=0;
    for (i=1;i<=limit[now];++i)
        if (!q[i])
        {
            place=i;
            break;
        }
    if (!place)
    {
        int task=0;
        for (i=1;i<=limit[now];++i)
            if (q[i])
                task+=((q[i]-1)*pow[now][i-1]);
        if (task>=0&&task<n)
            F[num]=a[task]%MOD;
        return F[num];
    }
    for (int i=1;i<=now;++i)
    {
        int task=num+pow[now+1][place-1]*i;
        F[num]=F[num]*DP(now,task,MOD)%MOD;
    }
    return F[num];
}

void work()
{
    int now=2;
    for (int k=1;k<=m;++k)
    {
        if (now>d[p[k]]) continue;
        while (now<d[p[k]]) ++now;
        for (int turn=1;turn<=5;++turn)
        {
            ++T;
            for (int x=k;x<=m;++x)
            {
                int i=p[x];
                if (d[i]!=now) break;
                if (ans[i]) continue;
                int tmp;
                if (mark[i])
                    tmp=(c[i]+1)%MOD[turn];
                else
                {
                    int num=0;
                    for (int dust=1;dust<=limit[now];++dust)
                        num+=(pow[now+1][limit[now]-dust]*s[i][dust]);
                    tmp=(c[i]+DP(now,num,MOD[turn]))%MOD[turn];
                }
                for (int cut=L[turn];cut<=R[turn];++cut)
                    if (tmp%prime[cut]==0)
                    {
                        ans[i]=prime[cut];
                        break;
                    }
            }
        }
        ++now;
    }
}

void print()
{
    for (int i=1;i<=m;++i)
        (ans[i])?printf("%d\n",ans[i]):puts("-1");
}

int main()
{
    base_limit();
    get_prime();
    power();
    init();
    work();
    print();
    return 0;
}