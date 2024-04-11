#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int d[22];
struct str{
    str(){}
    str(int x,int w):w(w),x(x){}
    int w, x;
    bool operator<(const str &l)const{
        return x<l.x;
    }
}p[1<<20|5];
int n, m;

struct tr{
    static const int N_ = 1<<20;
    int T[N_<<1];
    void update(int x, int w){
        x += N_;
        while(x)T[x]+=w, x>>=1;
    }
    int read(int x,int y){
        x+=N_, y+=N_;
        int ret = 0;
        while(x<=y){
            if(x&1)ret += T[x];
            if(!(y&1))ret += T[y];
            x = (x+1)>>1, y = (y-1)>>1;
        }
        return ret;
    }
}Tr;
ll q[22];
ll sm[22];
ll A[22];

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<1<<n;i++){
        int x;
        scanf("%d",&x);
        p[i] = str(x,i);
    }
    sort(p,p+(1<<n));
    vector <int> v;
    for(i=0;i<1<<n;i++){
        if(i!=0 &&p[i].x != p[i-1].x){
            for(int j=0;j<v.size();j++){
                Tr.update(p[v[j]].w, 1);
            }
            v.clear();
        }
        int now = p[i].w;
        for(int j=0;j<n;j++){
            if(!(now&1<<j))now |= 1<<j;
            q[j+1] += Tr.read(p[i].w, now);
        }
        v.push_back(i);
    }
    for(i=0;i<1<<21;i++)Tr.T[i] = 0;
    v.clear();
    for(i=0;i<=1<<n;i++){
        if(i!=1<<n)v.push_back(i);
        if(i==1<<n || p[i].x != p[i+1].x){
            for(int j=0;j<v.size();j++){
                Tr.update(p[v[j]].w, 1);
            }
            for(int j=0;j<v.size();j++){
                int t = p[v[j]].w;
                int now = t;
                for(int k=0;k<n;k++){
                    if(!(now&1<<k))now |= 1<<k;
                    sm[k+1] += Tr.read(t, now) - 1;
                }
            }
            for(int j=0;j<v.size();j++)Tr.update(p[v[j]].w, -1);
            v.clear();
        }
    }
    for(i=1;i<=n;i++){
        A[i] = ((ll)1<<(n-i)) * ((ll)1<<(i-1)) * ((ll)((1<<i) - 1));
        A[i] -= sm[i];
    }
    int m;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        if(x == 0){printf("%lld\n",q[n]);continue;}
        int j;
        ll d = q[x]*2 - A[x];
        for(j=1;j<=x;j++){
            q[j] = A[j] - q[j];
        }
        for(j=x+1;j<=n;j++)q[j] -= d;
        printf("%lld\n",q[n]);
    }
    return 0;
}