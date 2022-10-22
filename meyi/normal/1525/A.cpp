#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define SZ(k) k.size()
#define ALL(k) k.begin(),k.end()
#define DEBUG(k...) fprintf(stderr,k)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chkmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		printf("%d\n",100/gcd(n,100-n));
	}
	return 0;
}