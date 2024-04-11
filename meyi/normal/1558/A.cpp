#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a,b,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&a,&b);
		if(a>b)swap(a,b);
		vector<int>ans;
		if(a+b&1){
			ri l=(a+b)/2-a,r=(a+b)-((a+b)/2-a);
			for(ri i=l;i<=r;++i)ans.push_back(i);
		}
		else{
			ri l=(a+b)/2-a,r=(a+b)-((a+b)/2-a);
			for(ri i=l;i<=r;i+=2)ans.push_back(i);
		}
		printf("%u\n",ans.size());
		for(auto i:ans)printf("%d ",i);
		printf("\n");
	}
	return 0;
}