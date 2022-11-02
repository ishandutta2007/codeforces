# include <iostream>
# include <cstdio>
# include <algorithm>
# include <functional>
using namespace std;

const int N = 100000+10;
int n, m, tot, a[N], b[N];

long long count(int c){
    long long cnt = 0;
    for(int i=0; i<c; i++)
    	cnt += max(0, b[i]-a[c-1-i]);
    return cnt;
}

long long recount(int c){
    long long cnt = 0;
    for(int i=0; i<c; i++) 
        cnt += (a[i]=min(a[i],b[c-1-i]));
    for(int i=0; i<c; i++)
        tot -= b[c-1-i]-a[i];
    return max(cnt-tot,0LL);
}

int main(){
    scanf("%d%d%d",&n,&m,&tot);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    for(int i=0; i<m; i++) scanf("%d",&b[i]);
    
    sort(a,a+n,greater<int>());
    sort(b,b+m);
    
    int L = 0, R = min(m,n)+1,mid;
    while(R-L>1)
        count(mid=(L+R)>>1)<=tot ? L=mid:R=mid;
    cout << L << ' ' << recount(L) << endl;
    return 0;
}