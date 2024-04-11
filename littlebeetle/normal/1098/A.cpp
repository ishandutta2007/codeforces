#include<cstdio>
#include<cstdlib>
using namespace std;
const int N=100002;
int n,i,j,k,a,b,h[N],t[N],v[N],dep[N],p[N],s[N];
long long S;
int min(int x,int y){
	return x<y?x:y;
}
void dfs(int i){
	if(dep[i]%2==1){
		S+=s[i]-s[p[i]];
	}
	else{
		s[i]=1<<30;
		int o=0;
		for(int j=h[i];j;j=t[j],o++)
			s[i]=min(s[i],s[v[j]]);
		if(s[i]<s[p[i]]){
			printf("-1");
			exit(0);
		}
		if(o)
		S+=s[i]-s[p[i]];
	}
	for(int j=h[i];j;j=t[j])
		dep[v[j]]=dep[i]+1,dfs(v[j]);
}
int main(){
	scanf("%d",&n);
	for(b=2;b<=n;b++){
		scanf("%d",&a);
		p[b]=a;
		t[++k]=h[a];h[a]=k;v[k]=b;
	}
	for(i=1;i<=n;i++)
		scanf("%d",s+i);
	dep[1]=1;
	dfs(1);
	printf("%I64d",S);
	//while(1);
}