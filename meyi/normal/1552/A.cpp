#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
string s,t;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		cin>>s;
		t=s;
		sort(t.begin(),t.end());
		ri ans=0;
		for(ri i=0;i<n;++i)ans+=(s[i]!=t[i]);
		printf("%d\n",ans);
	}
	return 0;
}