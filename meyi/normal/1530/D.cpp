#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(int &x,const int &y){if(x<y)x=y;}
template<class T>inline void ckmin(int &x,const int &y){if(x>y)x=y;}
int a[maxn],fr[maxn],m,n,t_case,to[maxn];
inline void add(int x,int y){
	to[x]=y;
	fr[y]=x;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)fr[i]=to[i]=0,scanf("%d",a+i);
		for(ri i=1;i<=n;++i){
			if(!fr[a[i]])add(i,a[i]);
		}
		vector<int>v1,v2,v3;
		for(ri i=1;i<=n;++i){
			if(!fr[i]&&!to[i])v3.push_back(i);
			else if(!to[i])v1.push_back(i);
			else if(!fr[i])v2.push_back(i);
		}
		if(v1.size()){
			ri lst=v1[0];
			for(auto i:v3)add(lst,i),lst=i;
			add(lst,v2[0]);
			for(ri i=1;i<v1.size();++i)add(v1[i],v2[i]);
		}
		else if(v3.size()){
			ri lst=v3[0];
			for(ri i=1;i<v3.size();++i)add(lst,v3[i]),lst=v3[i];
			ri tmp=fr[a[lst]];
			add(lst,a[lst]);
			add(tmp,v3[0]);
		}
		ri cnt=0;
		for(ri i=1;i<=n;++i)cnt+=(to[i]==a[i]);
		printf("%d\n",cnt);
		for(ri i=1;i<=n;++i)printf("%d ",to[i]);
		printf("\n");
	}
}