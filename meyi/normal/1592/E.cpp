#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int inf=0x3f3f3f3f,maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int a[maxn],ans,n,lst[21],pre[maxn];
struct my_queue{
	vector<int>ele;
	int hd;
	inline int front(){return ele[hd];}
	inline void pop(){++hd;}
	inline int size(){return ele.size()-hd;}
	inline void push(int k){ele.push_back(k);}
};
unordered_map<int,my_queue>pos[2][21];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		pre[i]=pre[i-1]^a[i];
	}
	for(ri i=0;i<=n;++i){
		if(i)
			for(ri j=20,bm=0;j;--j){
				bm|=(1<<j);
				if(a[i]&(1<<(j-1))){
					while(pos[i&1][j][pre[i]&bm].size()&&pos[i&1][j][pre[i]&bm].front()<lst[j])pos[i&1][j][pre[i]&bm].pop();
					if(pos[i&1][j][pre[i]&bm].size())ckmax(ans,i-pos[i&1][j][pre[i]&bm].front());
				}
				else lst[j]=i;
			}
		for(ri j=20,bm=0;j;--j){
			bm|=(1<<j);
			pos[i&1][j][pre[i]&bm].push(i);
		}
	}
	printf("%d",ans);
	return 0;
}