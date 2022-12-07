#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL P1 = 1000007;
const LL P2 = 10000007;
const LL MOD = 100000007;
LL p1[100010],p2[100010];
struct Node
{
    LL x,y;
    bool operator == (const Node &b) const
    {
        return x==b.x&&y==b.y;
    }
};
void add(Node &a,int x)
{
    a.x=(a.x*P1+x)%MOD;
    a.y=(a.y*P2+x)%MOD;
}
void Minn(Node &a,int x,int len)
{
    a.x=(a.x-(x*p1[len])%MOD+MOD)%MOD;
    a.y=(a.y-(x*p2[len])%MOD+MOD)%MOD;
}
void init()
{
    p1[0]=p2[0]=1;
    for (int i=1;i<100010;i++)
    {
        p1[i]=(p1[i-1]*P1)%MOD;
        p2[i]=(p2[i-1]*P2)%MOD;
    }
}
int lL1[100010];
char s[100010],ts[200010];
int p[200010];
int cal(char *s)
{
    int len=strlen(s);
    int cnt=0;
    for (int i=0; i<len; i++)
    {
        ts[cnt++]='#';
        ts[cnt++]=s[i];
    }
    ts[cnt++]='#';
    p[0]=0;
    int a=0,anss=1;
    for (int i=1; i<cnt; i++)
    {
        int low;
        if (p[a]+a<i) low=0;
        else low=min(p[2*a-i],2*a-i-(a-p[a]));
        int high=min(i,cnt-1-i);
        for (int j=low; j<=high; j++)
        {
            if (ts[i-j]==ts[i+j]) p[i]=j;
            else break;
        }
        if (p[a]+a<p[i]+i) a=i;
        if (p[i]>anss) anss=p[i];
    }
    return anss;
}
bool ok(int mid,int ll,int len)
{
    if (mid==0) return true;
    int tl=lL1[len-mid];
    if (tl==-1) return false;
    if (tl+mid>ll) return false;
    return true;
}
int ansl[10],ansr[10];
int main()
{
    init();
    while (scanf("%s",s)==1)
    {
        int len=strlen(s),now=0,tlen=0;
        Node Hash1,Hash2;
        Hash1.x=Hash1.y=Hash2.x=Hash2.y=0;
        for (int i=len-1;i>=0;i--)
        {
            if (now+tlen>i)
            {
                lL1[i]=-1;
                continue;
            }
            tlen++;
            int end=now+tlen-1;
            add(Hash1,s[i]);
            add(Hash2,s[end]);
            bool find=false;
            while (now+tlen<=i&&!find)
            {
                if (Hash1==Hash2) find=true;
                else
                {
                    Minn(Hash2,s[now],tlen-1);
                    now++;
                    add(Hash2,s[now+tlen-1]);
                }
            }
            if (!find) lL1[i]=-1;
            else lL1[i]=now;
        }
        cal(s);
        for (int i=0;i<len;i++)
            p[i]=(p[i*2+1]+1)/2;
        int ans=0;
        for (int i=0;i<len;i++)
        {
            int ll=i-p[i]+1,rr=i+p[i]-1;
            int L=0,R=len-1-rr;
            while (L+1<R)
            {
                int mid=(L+R)/2;
                if (ok(mid,ll,len)) L=mid;
                else R=mid;
            }
            int tlen;
            if (ok(R,ll,len)) tlen=R;
            else tlen=L;
            if (ans<tlen*2+rr-ll+1)
            {
                ans=tlen*2+rr-ll+1;
                ansl[1]=ll; ansr[1]=rr;
                if (tlen==0)
                {
                    ansl[0]=ansr[0]=-1;
                    ansl[2]=ansr[2]=-1;
                }
                else
                {
                    ansl[0]=lL1[len-tlen];
                    ansr[0]=ansl[0]+tlen-1;
                    ansl[2]=len-tlen;
                    ansr[2]=len-1;
                }
            }
        }
        if (ansl[0]==-1)
        {
            puts("1");
            printf("%d %d\n",ansl[1]+1,ansr[1]-ansl[1]+1);
        }
        else
        {
            puts("3");
            for (int i=0;i<3;i++)
                printf("%d %d\n",ansl[i]+1,ansr[i]-ansl[i]+1);
        }
    }
    return 0;
}