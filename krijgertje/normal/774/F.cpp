#include <cstdio>
#include <cassert>
using namespace std;

const int MAXN=50000;

int n;
int a[MAXN];
int b[MAXN];


int main() {
    scanf("%d",&n); for(int i=0;i<n;++i) scanf("%d",&a[i]);
    int p=n; while(p%7!=0) p+=n;
    for(int i=0;i<n;++i) b[i]=0; for(int i=0;i<p;++i) if(i%7!=6) ++b[i%n];
    int full=INT_MAX; for(int i=0;i<n;++i) if(b[i]!=0) { int cur=(a[i]-1)/b[i]; if(cur<full) full=cur; }
    bool any=false; for(int i=0;i<n;++i) { a[i]-=full*b[i]; assert(a[i]>0); if(a[i]<=b[i]) any=true; } assert(any);
    for(int i=0;i<p;++i) if(i%7!=6) if(--a[i%n]==0) { printf("%d\n",(i%n)+1); return 0; }
    assert(false);
    return 0;
}