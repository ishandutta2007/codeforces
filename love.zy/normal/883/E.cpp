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
int n,m;
#define MAXN (1200)
char s[1200];
char s2[1200][1200];
bool b2[1200][1200]={};
bool b[MAXN];
bool ski[MAXN]={};
#define Fork(i,k,n) for(int i=k;i<=n;i++)
int main()
{
    int n;
    Fork(i,'a','z') b[i]=1;
    scanf("%d%s%d",&n,s+1,&m);
    for(int i=1;i<=m;i++) scanf("%s",s2[i]+1);
    for(int i=1;i<=n;i++) {
        if (s[i]!='*') {
            b[s[i]]=0;
        }
        
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            
            if (s[j]=='*') {
                b2[i][ s2[i][j] ]=1;
                if (!b[s2[i][j]]) ski[i]=1;
            } else {
                if (s[j]!=s2[i][j] ) ski[i]=1;
            }
            
        }
    }
    int ans=0;
    Fork(i,'a','z') if (b[i]) {
        bool fl=0;
        for(int j=1;j<=m;j++) if (!ski[j]){
            if (!b2[j][i]) {fl=1;break;}
        }
        if (!fl) ans++;
    }
    cout<<ans<<endl;


    return 0;
}