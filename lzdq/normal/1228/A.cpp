#include<cstdio>
#include<cstring>
const int N=10;
bool Vis[N];
int l,r,Answer=-1;
inline bool Check(int x){
	memset(Vis,0,sizeof(Vis));
	while(x){
		int k=x%10;
		x/=10;
		if(Vis[k]) return 0;
		Vis[k]=1;
	}
	return 1;
}
inline void Find(){
	for(register int i=l;i<=r;i++)
		if(Check(i)) return Answer=i,void();
}
int main(){
	scanf("%d %d",&l,&r);
	Find();
	printf("%d\n",Answer);
	return 0;
}