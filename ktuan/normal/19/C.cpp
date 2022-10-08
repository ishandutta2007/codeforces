#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

struct Data{
    int len;
    int left,right; 
};

int cmp(Data a,Data b){
    if(a.len==b.len)return a.left<b.left;
    else return a.len<b.len;
}

int n;
int a[100010];
map<int,int> ma;
int next[100010];

Data ds[2200010];
int nd;
set<PII> se;

int main() {
    scanf("%d",&n);
    Rep(i,n)scanf("%d",a+i);
    Ford(i,n-1,0){
        if(ma.count(a[i]))next[i]=ma[a[i]];
        else next[i]=n;
        ma[a[i]]=i; 
    }
    Rep(i,n){
        int j=next[i];
        while(j<n){
            // check
            if(!se.count(MP(i,j))){
            int u=i,v=j;
            while(a[u]==a[v]){
                ++u,++v;
                if(u==j||v==n)break;
                se.insert(MP(u,v));
            }
            if(u==j){
                ds[nd].len=v-i;
                ds[nd].left=i;
                ds[nd].right=j-1;
                ++nd;   
                break;
            }
            }
            //
            j=next[j];  
        }   
    }
    sort(ds,ds+nd,cmp);
    int st=0;
    Rep(i,nd){
        if(ds[i].left>=st)st=ds[i].right+1;
    }
    printf("%d\n",n-st);
    For(i,st,n-1)printf("%d ",a[i]);
    
    return 0;   
}