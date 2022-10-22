#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
		if(a[1]<a[2])swap(a[1],a[2]);
		if(a[3]<a[4])swap(a[3],a[4]);
		if(a[1]<a[4]||a[3]<a[2])puts("NO");
		else puts("YES");
	}
	return 0;
}