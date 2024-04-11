#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=1010;
int m,n,t_case;
char s[maxn];
vector<int>ea[maxn],eb[maxn],ga[maxn],gb[maxn],p1,p2;
bool dfs(int x,int y,int z){
	if(!z)return true;
	for(ri i:ga[x])
		for(ri j:ea[y])
			if(dfs(i,j,z-1)){
				p1.push_back(i);
				p2.push_back(j);
				return true;
			}
	for(ri i:gb[x])
		for(ri j:eb[y])
			if(dfs(i,j,z-1)){
				p1.push_back(i);
				p2.push_back(j);
				return true;
			}
	return false;
}
int main(){
	srand(time(0));
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)ea[i]=eb[i]=ga[i]=gb[i]={};
		for(ri i=1;i<=n;++i){
			scanf("%s",s+1);
			for(ri j=1;j<=n;++j){
				if(s[j]=='a')ea[i].push_back(j),ga[j].push_back(i);
				if(s[j]=='b')eb[i].push_back(j),gb[j].push_back(i);
			}
		}
		if(m&1){
			puts("YES");
			m=m+1>>1;
			for(ri i=1;i<=m;++i)printf("1 2 ");
			printf("\n");
		}
		else{
			vector<int>id(n);
			for(ri i=0;i<n;++i)id[i]=i+1;
			random_shuffle(id.begin(),id.end());
			p1=p2={};
			for(ri i:id)
				if(dfs(i,i,m>>1)){
					puts("YES");
					for(ri j:p1)printf("%d ",j);
					printf("%d ",i);
					reverse(p2.begin(),p2.end());
					for(ri j:p2)printf("%d ",j);
					printf("\n");
					goto skip;
				}
			puts("NO");
			skip:;
		}
	}
	return 0;
}