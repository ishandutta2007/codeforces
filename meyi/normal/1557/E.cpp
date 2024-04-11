#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
string s;
int t_case;
inline bool ask(int x,int y){
	printf("%d %d\n",x,y);
	fflush(stdout);
	cin>>s;
	return s=="Done";
}
inline void solve(){
	while(true)
		for(ri i=1;i<9;++i)
			for(ri j=1;j<9;++j)
				if(ask(i,(i&1)?j:9-j))
					return;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--)solve();
	return 0;
}