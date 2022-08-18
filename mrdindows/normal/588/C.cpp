#include<bits/stdc++.h>
using namespace std;
#define endll           "\n"
#define INIT(n,m)       memset(n,m,sizeof(n))
#define REP(i,n)        for(int i=0;i<n;i++)
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define FORD(i,a,b)     for(int i=a;i>=b;i--)
#define PB              push_back
#define IN(a,b)         substr(a,b-a+1)
#define FF              first
#define SS              second
#define LEN(x)          ((int)x.size())
#define MM              1000000007
#define CHECK(x,y)      (((x%=y)+=y)%=y)
#define DEBUG(x)        {cout<<#x<<" = ";cout << (x) << endll;}
#define PR(v)           {cout<<#v<<" = ";for(auto _:v)cout<<_<<' ';cout<<endll;}
#define PRR(a,b,n)      {cout<<#a<<" = ";FOR(_,b,n)cout<<a[_]<<' ';cout<<endll;}
#define FOREACH(it, c)  for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define FILE_IO(a,b)    {freopen(a,"r",stdin);freopen(b,"w",stdout);}
struct  IO              {IO(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}_;
typedef long long ll;
typedef pair<int,int> ii;
int n,m,len,k,t,a,b;
/*
 Suppose cnt[x] = 2^y.
 cnt[x] <- 0
 cnt[x+y]++
 */
vector<int> v;
int cnt[1100051];


int read_int()
{
    const int BUSFIZE = 4096;
    static char inbuf[BUSFIZE + 16];
    static char *inp = inbuf;
    static char *linp = inbuf + BUSFIZE;
    if (*inp == 0)
    {
        memset(inbuf, 0, BUSFIZE);
        cin.read(inbuf, BUSFIZE);
        inp = inbuf;
    }
    while (*inp && (*inp < '0' || *inp > '9')) ++inp;
    int res = 0;
    while (*inp >= '0' && *inp <= '9')
    {
        res = res * 10 + *inp - '0';
        ++inp;
        if (inp == linp)
        {
            memset(inbuf, 0, BUSFIZE);
            cin.read(inbuf, BUSFIZE);
            inp = inbuf;
        }
    }
    ++inp;
    return res;
}

#define LOG2(x) ((int)((--(upper_bound(v.begin(),v.end(),x)))-v.begin()))

int main(){
    vector<int> v;
    for(ll j=1;j<=2097152;j*=2) v.PB(j);
    n = read_int();
    REP(i,n) { a = read_int(); cnt[a]++; }
    for(int i=0;i<=1100050;)
        if(cnt[i] <= 1) i++;
        else{
            int idx = LOG2(cnt[i]);
            cnt[i] -= v[idx];
            cnt[i+idx]++;
        }
    int ans = 0;
    FOR(i,0,1100050) if(cnt[i]) ans++;
    printf("%d\n",ans);
    return 0;
}