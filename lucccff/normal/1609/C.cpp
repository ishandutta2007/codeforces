#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[100010],b[100010];

const int MAXN=1000010;
bool notprime[MAXN];// false  true 
void init(){
    memset(notprime,false,sizeof(notprime));
    notprime[0]=notprime[1]=true;
    for(int i=2;i<MAXN;i++)
    if(!notprime[i]){
        if(i>MAXN/i)continue;
        for(int j=i*i;j<MAXN;j+=i)
        notprime[j]=true;
    }
}

int main() {
    int i,j,k,l,m,n,t;
    LL ans;
    //cin>>t;
    scanf("%d",&t);
    init();
    while(t--) {
        scanf("%d%d",&n,&m);
        ans=0;
        for(i=0;i<n;i++) {
            scanf("%d",&k);
            if (k==1) {
                b[i]=0;
            }
            else if (notprime[k]) {
                b[i]=2;
            }
            else {
                b[i]=1;
            }
        }
        for(i=0;i<m;i++) {
            k=0;
            l=0;
            for(j=i;j<n;j+=m) {
                if (b[j]==0) {
                    ans+=k-l;
                    k++;
                    l++;
                }
                else if (b[j]==1) {
                    ans+=l;
                    k=l+1;
                    l=0;
                }
                else {
                    k=0;
                    l=0;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}