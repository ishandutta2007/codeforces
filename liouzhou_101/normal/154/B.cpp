#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

const int MaxN=100010;
const int MaxP=316;

int n,m;
vector<int> factor[MaxN];
int flag[MaxN],prime[MaxN],limit[MaxN];

void get_prime()
{
    for (int i=2;i<=100000;++i)
    {
        if (!flag[i]) prime[++prime[0]]=i;
        for (int j=2;i*j<=100000;++j)
            flag[i*j]=1;
    }
    for (int k=2;k<=100000;++k)
    {
        int tmp=k;
        for (int i=1;i<=prime[0];++i)
        {
            if (prime[i]*prime[i]>tmp) break;
            if (tmp%prime[i]==0)
            {
                factor[k].push_back(i);
                while (tmp%prime[i]==0) tmp/=prime[i];
            }
        }
        if (tmp>1)
        {
            int L=1,R=prime[0];
            while (L<=R)
            {
                int mid=(L+R)>>1;
                if (tmp==prime[mid])
                {
                    factor[k].push_back(mid);
                    break;
                }
                (prime[mid]<tmp)?L=mid+1:R=mid-1;
            }
        }
    }
}

void work()
{
    memset(flag,0,sizeof(flag));
    scanf("%d%d",&n,&m);
    char s[4];
    while (m--)
    {
        int x;
        scanf("%s%d",s,&x);
        if (s[0]=='+')
        {
            if (flag[x])
            {
                puts("Already on");
                continue;
            }
            int tmp=0;
            for (vector<int>::iterator it=factor[x].begin();it!=factor[x].end();++it)
                if (limit[*it])
                {
                    tmp=limit[*it];
                    break;
                }
            if (tmp)
            {
                printf("Conflict with %d\n",tmp);
                continue;
            }
            puts("Success");
            flag[x]=1;
            for (vector<int>::iterator it=factor[x].begin();it!=factor[x].end();++it)
                limit[*it]=x;
        }
        else
        {
            if (!flag[x])
            {
                puts("Already off");
                continue;
            }
            puts("Success");
            flag[x]=0;
            for (vector<int>::iterator it=factor[x].begin();it!=factor[x].end();++it)
                limit[*it]=0;
        }
    }
}

int main()
{
    get_prime();
    work();
    return 0;
}