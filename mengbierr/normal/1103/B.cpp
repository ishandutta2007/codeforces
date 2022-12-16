#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repd(i,x,n) for(int i=x;i<=n;i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define gbtb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MSC0(X) memset((X), '\0', sizeof((X)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eps 1e-6
#define gg(x) getInt(&x)
#define db(x) cout<<"== [ "<<x<<" ] =="<<endl;
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD){ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
inline void getInt(int* p);
const int maxn=1000010;
const int inf=0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
char s[maxn];
char re[1000];
char ask(ll j,ll k)
{
    k=min(k,2000000000ll);
    printf("? %lld %lld\n",j,k);
    fflush(stdout);
    scanf("%s",re);
    return re[0];
}
int main()
{
    int o=-1;
    while(1)
    {

        scanf("%s",s);
        if(s[0]=='e'||s[0]=='m')
        {
            break;
        }else
        {
            char w=ask(0ll,1ll);
            if(w=='x')
            {
                printf("! 1\n");
                fflush(stdout);
            }else
            {
                ll j=1;ll k=2;
                int flag=0;
                repd(i,1,30)
                {
                    w=ask(j,k);
                    if(w=='x')
                    {
                        flag=1;
                        break;
                    }else
                    {
                        j=k;
                        k*=2;
                    }
                }
                if(flag)
                {
                    ll mid=(j+k)>>1;
                    repd(i,1,29)
                    {
                        mid=(j+k)>>1;
                        w=ask(mid,k);
                        if(w=='x')
                        {
                            j=mid;
                        }else
                        {

                            k=mid;

                        }
                    }
                    printf("! %d\n",max(j,k));
                    fflush(stdout);
                }
            }

        }
    }
    return 0;
}

inline void getInt(int* p) {
    char ch;
    do {
        ch = getchar();
    } while (ch == ' ' || ch == '\n');
    if (ch == '-') {
        *p = -(getchar() - '0');
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 - ch + '0';
        }
    }
    else {
        *p = ch - '0';
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 + ch - '0';
        }
    }
}