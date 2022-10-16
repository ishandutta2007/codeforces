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

int n,x;ll res=0;
vi a,b;

int cmp(vi a,vi b)
{
    if(res<0||a.empty()) return -1;
    if(res>0||b.empty()) return 1;
    int it=0;
    while(it<max(a.size(),b.size()))
    {
        if(it>=b.size()||a[it]>b[it]) return 1;
        if(it>=a.size()||a[it]<b[it]) return -1;
        it++;
    }
    return 0;
}

void init(void)
{
    scanf("%d",&n);
    f(i,n)
    {
        scanf("%d",&x);
        res+=x;
        if(x>0) a.pb(x);
        else b.pb(-x);
    }
}

void process(void)
{
    if(cmp(a,b)==0) {if(x>0) printf("first");else printf("second");return;}
    if(cmp(a,b)>0) printf("first");else printf("second");
}

int main(void)
{
    init();
    process();
    return 0;
}