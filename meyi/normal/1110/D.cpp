#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int m,n;
int main(){
	scanf("%d%d",&n,&m);
	map<int,int>cnt;
	for(ri i=1,x;i<=n;++i){
		scanf("%d",&x);
		++cnt[x];
	}
	vector<vector<int>>f(3,vector<int>(3));
	int pre=-1;
	for(const auto &x:cnt){
		vector<vector<int>>g(3,vector<int>(3));
		if(x.first==pre+1){
			for(ri i=0;i<3;++i)
				for(ri j=0;j<3;++j)
					for(ri k=0;k<3;++k)
						if(i+j+k<=x.second)
							ckmax(g[j][k],f[i][j]+(x.second-i-j-k)/3+k);
		}
		else{
			for(ri i=0;i<3;++i)
				if(i<=x.second)
					ckmax(g[0][i],f[0][0]+(x.second-i)/3+i);
		}
		f=g,pre=x.first;
	}
	printf("%d",f[0][0]);
	return 0;
}