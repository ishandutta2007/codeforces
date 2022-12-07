/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=100005;
set<int> s[maxn];
int num[maxn],ord[maxn],n,m,sum,e[maxn];
struct res{int x,y,z;};
vector<res> ans;

bool cmp(int x,int y){return num[x] < num[y];}
set<int>::iterator it1,it2;

int main()
{
    scanf("%d%d",&n,&m); ans.clear();
    for(int i=1;i<=n;i++)
    {
        ord[i] = i;
        int k;scanf("%d",&k);
        sum+=k;s[i].clear();num[i]=k;
        while(k--)
        {
            int x;scanf("%d",&x);
            s[i].insert(x);
        }
    }
    sort(ord+1,ord+n+1,cmp);
    for(int i = 1; i <= n; ++ i) e[i] = sum / n;
    int cha = sum - e[1] * n;
    for(int i = 1; i <= cha; ++ i) e[ord[n - i + 1]]++;
    int bg=1,ed=n;
    while(bg<ed)
    {
        int l=ord[bg],r=ord[ed];
        if(num[l]>=e[l]){bg++;continue;}
        if(num[r]<=e[r]){ed--;continue;}
        int last = 0;
        while(num[l]<e[l] && num[r]>e[r])
        {
            it1 = s[r].upper_bound(last);
            if(it1 == s[r].end()) break;
            int val = *it1;
            it2 = s[l].lower_bound(val);
            if(it2!=s[l].end() && (*it2) == val){last = val; continue;}
            num[l]++;num[r]--;
            s[r].erase(val);s[l].insert(val);
            ans.pb({r,l,val});
        }
    }
    printf("%d\n",(int)ans.size());
    for(res p : ans) printf("%d %d %d\n",p.x,p.y,p.z);
    return 0;
}