#include <algorithm>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 100000000000000000ll
#define gc getchar()
#define abs(x) ((x)>0?(x):(-(x)))
#define X first
#define Y second
#define mp(x,y) make_pair((x),(y))
#define eps (1e-8)
#define pb push_back
#define pf(x) ((x)*(x))
#define il inline

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;

il ll read()
{
	char c=gc;ll u=0,f=1;
	while(c!='-' && (c<'0' || '9'<c))c=gc;
	if(c=='-'){
		f=-1;
		c=gc;
	}
	while('0'<=c && c<='9'){
		u=u*10+c-'0';
		c=gc;
	}
	return u*f;
}
il char readc()
{
	for(;;){
		char c=gc;
		if('A'<=c && c<='Z' || 'a'<=c && c<='z')return c;
	}
}
il int read_digit()
{
	for(;;){
		char c=gc;
		if('0'<=c && c<='9')return c-'0';
	}
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
template <typename T>inline void updmax(T &a,T b){if(b>a)a=b;}
template <typename T>inline void updmin(T &a,T b){if(b<a)a=b;}
inline void swap(int &a,int &b){int t=a;a=b;b=t;}

inline void fileio(string s){
	if(s=="txt"){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	else{
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

int a[10][10],grp[10];
int ans[10][5010][20];
struct edge{
    int beg,end;
    edge(int x,int y){beg=x;end=y;}
    edge(){}
};

int G2[10][10],du[10];
int tpx[10];

const int OBSTACLE=-1;
const int AIR=0;

bool dig[10][5010];

int main()
{
    int n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=read();
        }
        a[i][i]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j] = a[i][j]|(a[i][k] & a[k][j]);
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(grp[i]==0){
            grp[i]=++cnt;
            vector<int> v;
            v.pb(i);
            for(int j=i+1;j<=n;j++){
                bool f=true;
                for(auto u:v){
                    if(!(a[u][j] && a[j][u])){
                        f=false;
                        break;
                    }
                }
                if(f){
                    grp[j]=i;
                    v.pb(j);
                }
            }
        }
    }
    vector<edge> E;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j])G2[grp[i]][grp[j]]=1;
        }
    }
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=cnt;j++){
            if(i==j)continue;
            if(G2[i][j]){
                du[j]++;
                E.pb(edge(i,j));
            }
        }
    }
    queue<int> q;
    int tmp=0;
    for(int i=1;i<=cnt;i++){
        if(du[i]==0){
            tpx[i]=++tmp;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=1;i<=cnt;i++){
            if(i==u)continue;
            if(G2[u][i]){
                du[i]--;
                if(du[i]==0){
                    tpx[i]=++tmp;
                    q.push(i);
                }
            }
        }
    }
    int a=5,b=max(E.size()*4,n);
    for(int i=2;i<=cnt*2;i+=2){
        for(int j=1;j<=a;j++){
            for(int k=1;k<=b;k++){
                ans[j][k][i]=OBSTACLE;
            }
        }
    }
    int m=E.size();
    for(int i=0;i<m;i++){
        int top=tpx[E[i].beg]*2,bot=tpx[E[i].end]*2;
        for(int j=top;j!=bot;j+=2){
            ans[1][i*2+1][j]=AIR;
        }
    }
    for(int i=1;i<=cnt;i++){
        int level=tpx[i]*2;
        tmp=0;
        for(int j=1;j<=n;j++){
            if(grp[j]==i){
                tmp++;
                ans[5][tmp][level-1]=j;
            }
        }
        memset(dig,0,sizeof(dig));
        for(int i=1;i<=b;i++)dig[3][i]=true;
        for(int i=1;i<=tmp;i++)dig[5][i]=true;
        dig[4][1]=true;
        for(int j=0;j<m;j++){
            if(E[j].beg==i || E[j].end==i){
                dig[1][j*2+1]=dig[2][j*2+1]=true;
            }
        }
        for(int x=1;x<=a;x++){
            for(int y=1;y<=b;y++){
                if(dig[x][y])continue;
                if(dig[x][y+1] || dig[x][y-1] || dig[x+1][y] || dig[x-1][y]){
                    ans[x][y][level-1]=OBSTACLE;
                }
            }
        }
    }
    cout<<b<<' '<<a<<' '<<cnt*2<<'\n';
    for(int i=1;i<=cnt*2;i++){
        for(int x=1;x<=a;x++){
            for(int y=1;y<=b;y++){
                if(ans[x][y][i]>0)cout<<ans[x][y][i];
                else putchar(ans[x][y][i]==0?'.':'#');
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}