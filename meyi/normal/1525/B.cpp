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
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		bool flag=true;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),flag&=(a[i]==i);
		if(flag){puts("0");continue;}
		if(a[1]==1||a[n]==n)puts("1");
		else if(a[1]==n&&a[n]==1)puts("3");
		else puts("2");
	}
	return 0;
}