#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,pos[maxn],t_case;
vector<int>ans;
inline void rev(int k){
	if(k==1)return;
	if(ans.size()&&ans.back()==k)ans.pop_back();
	else ans.push_back(k);
	for(ri i=1;i*2<k;++i){
		swap(a[i],a[k-i+1]);
		pos[a[i]]=i;
		pos[a[k-i+1]]=k-i+1;
	}
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		bool flag=false;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i),pos[a[i]]=i;
			if((a[i]&1)!=(i&1))flag=true;
		}
		if(flag){
			puts("-1");
			continue;
		}
		ans.clear();
		for(ri i=n-1;i;i-=2){
			if(pos[i]==i&&pos[i+1]==i+1)continue;
			if(pos[i+1]==pos[i]+1){
				rev(pos[i+1]);
				rev(i+1);
			}
			else{
				if(pos[i+1]!=pos[i]-1){
					rev(pos[i+1]);
					rev(pos[i]-1);
				}
				if(pos[i]!=i||pos[i+1]!=i+1){
					rev(pos[i]+1);
					if(pos[i]!=i||pos[i+1]!=i+1){
						rev(3);
						if(pos[i]!=i||pos[i+1]!=i+1)rev(i+1);
					}
				}
			}
		}
		if(ans.size()>(n*5)/2)puts("-1");
		else{
			printf("%u\n",ans.size());
			for(auto i:ans)printf("%d ",i);
			printf("\n");
		}
	}
	return 0;
}