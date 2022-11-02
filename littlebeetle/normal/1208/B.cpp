#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
const int N=2002;
bool s[N];
int n,i,j,k,x,a[N],ans=1<<30,opt;
map<int,int>f;
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		if(f[x])a[i]=f[x];
		else{
			f[x]=++k;
			a[i]=f[x];
		}
	}
}
int min(int x,int y){
	return x<y?x:y;
}
void work(){
	for(k=0;k<n;k++){
		memset(s,0,sizeof(s));
		opt=1;
		for(i=1;i<=k;i++){
			if(s[a[i]])
				opt=0;
			s[a[i]]=1;
		}
		for(i=n;i>=k;i--){
			if(opt)
				ans=min(ans,i-k);
			if(s[a[i]])
				opt=0;
			s[a[i]]=1;
		}
	}
	printf("%d",ans);
	//while(1);
}
int main(){
	init();
	work();
}