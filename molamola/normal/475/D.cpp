#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;

int gcd(int x,int y){return y?gcd(y,x%y):x;}
struct str{
    str(){}
    str(int x,int w):x(x),w(w){}
    int x, w;
    bool operator==(const str &a){
        return x == a.x;
    }
}s[100010];

int p[100010], cnt;
map <int, long long> M;

int main(){
    int n, q;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)scanf("%d",p+i);
    for(i=0;i<n;i++){
        for(int j=0;j<cnt;j++)s[j].x = gcd(s[j].x, p[i]);
        s[cnt++] = str(p[i], i);
        cnt = unique(s, s+cnt) - s;
        for(int j=0;j<cnt-1;j++)M[s[j].x] += s[j+1].w - s[j].w;
        M[p[i]] += i - s[cnt-1].w + 1;
    }
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%lld\n",M[x]);
    }
    return 0;
}