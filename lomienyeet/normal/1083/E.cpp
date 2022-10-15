#include <bits/stdc++.h>
#pragma GCC optimize("O3","inline","unroll-loops")
#pragma GCC option("arch=native","tune=native","no-zero-upper","D_GLIBCXX_PARALLEL")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx,bmi,bmi2,lzcnt")
using namespace std;
#define int long long
#define double long double
#define ff first
#define ss second
#define rect pair<pair<int,int>,int>
static char pbuf[1<<19],*p1=pbuf,*p2=pbuf,obuf[1<<19],*o=obuf;
#define gc() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1<<19,stdin),p1==p2)?EOF:*p1++
#define pc(x) (o-obuf<1<<19)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int max(int a,int b){return a>b?a:b;}
inline int read(){
    int x=0;register int c=gc();
    while(c<48||c>57)c=gc();
    while(c>=48&&c<=57){x=(x<<1)+(x<<3)+c-48;c=gc();}
    return x;
}
inline void write(int x){
    if(x>9)write(x/10);
    pc(x%10+48);
}
struct line{
    int m,c;
    int y(int x){
        return m*x+c;
    }
    double intersect(const line &l){
        return ((double)(1.0*(l.c-c))/(double)(1.0*(m-l.m)));
    }
};
deque<line> cht;
void upd(int m,int c){ // add a new line
    line dz=(line){m,c};
    while(cht.size()>=2 && dz.intersect(cht[0])>=cht[0].intersect(cht[1]))cht.pop_front();
    cht.push_front(dz);
}
int qry(int x){ // query a val
    while(cht.size()>=2  && cht.back().y(x)<=cht[cht.size()-2].y(x))cht.pop_back();
    return cht.back().y(x);
}
signed main(){
    int n=read();
    rect arr[n+1];
    for(int i=1;i<=n;i++){
        arr[i].ff.ff=read();
        arr[i].ff.ss=read();
        arr[i].ss=read();
    }
    sort(arr+1,arr+n+1);
    int maxi=0;
    upd(0,0);
    for(int i=1;i<=n;i++){
        int cur=arr[i].ff.ff*arr[i].ff.ss-arr[i].ss;
        cur+=qry(arr[i].ff.ss);
        maxi=max(maxi,cur);
        upd(-arr[i].ff.ff,cur);
    }
    write(maxi);
    fwrite(obuf,o-obuf,1,stdout);
}