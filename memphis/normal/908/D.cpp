#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <bitset>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define fi first
#define se second

using namespace std;

typedef long long ll;

const int N=1005;
const int P=1000000007;

int power(int x,int v){
    int ans=1;
    for(;v;v>>=1,x=(ll)x*x%P) if(v&1) ans=(ll)ans*x%P;
    return ans;
} 

int k,a,b,pa,pb,f[N][N];

int main(){
	scanf("%d%d%d",&k,&a,&b);
    int t=power(a+b,P-2);
	pa=1ll*a*t%P;pb=1ll*b*t%P;
	f[0][1]=1;
	int ans=0;
    rep(i,0,k-1){
        rep(j,1,k-1){
			int t=f[i][j];
			f[i][j+1]=(f[i][j+1]+1ll*t*pa)%P;
			if(i+j>=k){
				ans=(ans+1ll*t*pb%P*(i+j))%P;
			}else{
				f[i+j][j]=(f[i+j][j]+1ll*t*pb)%P;
			}
		}
	}
    t=power((P+1-pa)%P,P-2);
	t=1ll*pa*pb%P*t%P*t%P;
	for(int i=0;i<k;i++){
		ans=(ans+1ll*f[i][k]*(i+k+t))%P;
	}
	printf("%d\n",ans);
	return 0;
}