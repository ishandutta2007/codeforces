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

ll a1,b1,a2,b2;

void init(void)
{
    scanf("%I64d%I64d%I64d%I64d",&a1,&b1,&a2,&b2);
}

void process(void)
{
    int cnt1=0,cnt2=0,flag;
    ll s1=a1*b1,s2=a2*b2;
    if(s1==s2)
    {
        printf("0\n%I64d %I64d\n%I64d %I64d",a1,b1,a2,b2);
        return;
    }
    ll d=__gcd(s1,s2);
    ll t1=s1/d,t2=s2/d;
    if(t1==1)
    {
        while(t2%2==0) {cnt1++;t2/=2;}
        while(t2%3==0) {cnt2++;t2/=3;}
        if(t2!=1)
        {
            printf("-1");return;
        }
        printf("%d\n",cnt1+cnt2*2);
        f(i,cnt2)
        {
            if(a2%3==0) a2=a2*2/3;else b2=b2*2/3;
        }
        f(i,cnt1+cnt2)
        {
            if(a2%2==0) a2/=2;else b2/=2;
        }
        printf("%I64d %I64d\n%I64d %I64d",a1,b1,a2,b2);
        return;
    }
    else if(t2==1)
    {
        while(t1%2==0) {cnt1++;t1/=2;}
        while(t1%3==0) {cnt2++;t1/=3;}
        if(t1!=1)
        {
            printf("-1");return;
        }
        printf("%d\n",cnt1+cnt2*2);
        f(i,cnt2)
        {
            if(a1%3==0) a1=a1*2/3;else b1=b1*2/3;
        }
        f(i,cnt1+cnt2)
        {
            if(a1%2==0) a1/=2;else b1/=2;
        }
        printf("%I64d %I64d\n%I64d %I64d",a1,b1,a2,b2);
        return;
    }
    else if(t1&1)
    {
        flag=2;
        while(t1%3==0) {cnt1++;t1/=3;}
        if(t1!=1)
        {
            printf("-1");return;
        }
        while(t2%2==0) {cnt2++;t2/=2;}
        if(t2!=1)
        {
            printf("-1");return;
        }
    }
    else
    {
        flag=1;
        while(t2%3==0) {cnt2++;t2/=3;}
        if(t2!=1)
        {
            printf("-1");return;
        }
        while(t1%2==0) {cnt1++;t1/=2;}
        if(t1!=1)
        {
            printf("-1");return;
        }
    }
    if(flag==1)
    {
        if(cnt1>=cnt2)
        {
            printf("%d\n",cnt1);
            f(i,cnt2)
            {
                if(a2%3==0) a2=a2*2/3;else b2=b2*2/3;
            }
            f(i,cnt1-cnt2)
            {
                if(a1%2==0) a1/=2;else b1/=2;
            }
            printf("%I64d %I64d\n%I64d %I64d",a1,b1,a2,b2);return;
        }
        printf("%d\n",cnt2*2-cnt1);
        f(i,cnt2)
        {
            if(a2%3==0) a2=a2*2/3;else b2=b2*2/3;
        }
        f(i,cnt2-cnt1)
        {
            if(a2%2==0) a2/=2;else b2/=2;
        }
        printf("%I64d %I64d\n%I64d %I64d",a1,b1,a2,b2);return;
    }
        if(cnt2>=cnt1)
        {
            printf("%d\n",cnt2);
            f(i,cnt1)
            {
                if(a1%3==0) a1=a1*2/3;else b1=b1*2/3;
            }
            f(i,cnt2-cnt1)
            {
                if(a2%2==0) a2/=2;else b2/=2;
            }
            printf("%I64d %I64d\n%I64d %I64d",a1,b1,a2,b2);return;
        }
        printf("%d\n",cnt1*2-cnt2);
        f(i,cnt1)
        {
            if(a1%3==0) a1=a1*2/3;else b1=b1*2/3;
        }
        f(i,cnt1-cnt2)
        {
            if(a1%2==0) a1/=2;else b1/=2;
        }
        printf("%I64d %I64d\n%I64d %I64d",a1,b1,a2,b2);return;
}

int main(void)
{
    init();
    process();
    return 0;
}