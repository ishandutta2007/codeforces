#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;
const double pi=3.1415926535897932384626;
const double eln=2.718284590452353602874;
#define IN freopen("tmp.in", "r", stdin);
#define OU freopen("tmp.ou", "w", stdout);
#define mp make_pair
#define pb push_back
#define pr1(x) printf("Case %d: ", x);
#define pn1(x) printf("Case %d:\n",x);
#define pr2(x) printf("Case #%d: ", x);
#define pn2(x) printf("Case #%d:\n",x);
#define sqr(x) (x)*(x)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn=200005;
struct node
{
    int son[2];
    int state,ori;
}tr[maxn<<5];
char s[30];
int n,a[6],nodecnt;
string codestring;

string encode(int p)
{
    string ret="";
    for(int i=7;i>=0;i--)
    {
		ret += (char)(!!(p&(1<<i))+48);
    }
    return ret;
}

int newnode()
{
    nodecnt++;
    tr[nodecnt].state=tr[nodecnt].ori=0;
    tr[nodecnt].son[0]=tr[nodecnt].son[1]=0;
    return nodecnt;
}

void dfs(int now,int dep)
{
    if(dep > a[5]) return;
    if(dep==a[5])
    {
        if(s[0]=='-'){ tr[now].state|=2; tr[now].ori=2; }
        else { tr[now].state|=1; tr[now].ori=1; }
        return;
    }
    int num=codestring[dep]-48;
    if(tr[now].son[num]==0) tr[now].son[num]=newnode();
    dfs(tr[now].son[num], dep+1);
    tr[now].state|=tr[tr[now].son[num]].state;
}

void addnode()
{
    int rt=0; codestring="";
    for(int i=1;i<=4;i++)codestring+=encode(a[i]);
    dfs(rt,0);
}

vector<string> ans;

bool flag=false;

string decode(string tmp)
{
    string ret="";
    vi v; v.clear();
    int bs=128,sum=0;
    for(int i=0;i<tmp.length();i++)
    {
        sum+=(tmp[i]-48)*bs;bs>>=1;
        if(i%8==7)
        {
            v.pb(sum);
            bs=128;sum=0;
        }
        //sum+=(tmp[i]-48)*bs;
        //bs>>=1;
    }
    if(sum>0)v.pb(sum);
    while(v.size()<4)v.pb(0);
    for(int i=0;i<4;i++)
    {
        if(i>0)ret+='.';
        ret+=to_string(v[i]);
    }
    ret+='/';
    ret+=to_string(tmp.length());
    return ret;
}

void find(int now, string st)
{
    if(tr[now].ori>0 && tr[now].ori<tr[now].state){ flag=true;return; }
    if(tr[now].state<=1)return;
    if(tr[now].state==2)
    {
        //cout<<st<<endl;
        ans.pb(decode(st));
        return;
    }
    if(tr[now].son[0]+tr[now].son[1]==0){flag=true;return;}
    if(tr[now].son[0]>0)find(tr[now].son[0],st+"0");
    if(flag)return;
    if(tr[now].son[1]>0)find(tr[now].son[1],st+"1");
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        int len=strlen(s);
        bool f=false;
        for(int i=0;i<len;i++)if(s[i]=='/'){f=true;break;}
        if(!f){s[len++]='/';s[len++]='3';s[len++]='2';s[len]=0;}
        sscanf(s+1,"%d.%d.%d.%d/%d",&a[1],&a[2],&a[3],&a[4],&a[5]);
        addnode();
    }
    ans.clear();find(0,"");
    if(flag){puts("-1");return 0;}
    printf("%d\n",(int)ans.size());
    for(string p : ans)cout<<p<<endl;
    return 0;
}