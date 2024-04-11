#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int n,t_case,x,y;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ri k=n%11;
		puts(n>=k*111&&(n-k*111)%11==0?"YES":"NO");
	}
	return 0;
}