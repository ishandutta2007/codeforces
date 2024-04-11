#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=5e5+10;
int a[maxn],n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+n-i+1);
		typedef pair<int,int> pii;
		#define fi first
		#define se second
		vector<pii>ans1;
		vector<int>ans2;
		ri cnt=0;
		while(n){
			ri pos=n-1;
			while(pos&&a[pos]!=a[n])--pos;
			if(pos){
				vector<int>tmp;
				for(ri i=n-1;i>pos;--i){
					ans1.emplace_back((cnt+n)*2-pos-i,a[i]);
					tmp.push_back(a[i]);
				}
				ans2.push_back((n-pos)*2);
				cnt+=n-pos;
				n=pos-1;
				for(const ri &i:tmp)a[++n]=i;
			}
			else{puts("-1");goto skip;}
		}
		printf("%d\n",(int)ans1.size());
		for(const pii &i:ans1)printf("%d %d\n",i.fi,i.se);
		printf("%d\n",(int)ans2.size());
		for(const ri &i:ans2)printf("%d ",i);
		printf("\n");
		skip:;
	}
	return 0;
}