#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,a,b) for(int i=(a);i>=(b);i--)
#define RVC(i,S) for(int i=0;i<(S).size();i++)
#define RAL(i,u) for(int i=fr[u];i!=-1;i=e[i].next)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
     
template<class T> inline
void read(T& num) {
    bool start=false,neg=false;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=true;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
/*============ Header Template ============*/

struct edge {
    int next,to;
};

const int maxn=(int)(4e5)+5;
LL cnt[maxn],sum[maxn],val[maxn];
int fr[maxn];
edge e[maxn<<1];
int n,k,tote=0;
LL res=(LL)(1e15);

inline void addone(int u,int v) {
    ++tote;
    e[tote].next=fr[u];fr[u]=tote;e[tote].to=v;
}

inline void addedge(int u,int v) {
    addone(u,v);addone(v,u);
}

void dfs(int x,int f,LL c) {
    res=min(res,c+val[x]);
    RAL(i,x) if(e[i].to!=f) 
        dfs(e[i].to,x,c+val[x]-(val[e[i].to]+sum[e[i].to])+k-sum[e[i].to]);
}

void gen(int x,int f) {
    sum[x]=cnt[x];
    RAL(i,x) if(e[i].to!=f) {
        gen(e[i].to,x);
        sum[x]+=sum[e[i].to];
        val[x]+=val[e[i].to]+sum[e[i].to];
    }
}

int main() {
    memset(val,0,sizeof(val));
    read(n);read(k);k<<=1;
    REP(i,1,k) {
        int x;
        read(x);
        cnt[x]++;
    }
    memset(fr,-1,sizeof(fr));
    REP(i,1,n-1) {
        int u,v;
        read(u);read(v);
        addedge(u,v);
    }
    gen(1,0);dfs(1,0,0);
    printf("%I64d\n",res);
    return 0;
}