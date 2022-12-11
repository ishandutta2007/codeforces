#include<cstdio>
#include<algorithm>
using namespace std;

int a[100001],b[100001],c[100001];
bool cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),b[i]=i;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		int o=b[i];
		for(int j=o+a[o];j<=n;j+=a[o])
			if(a[j]>a[o]&&!c[j])c[o]=1;
		for(int j=o-a[o];j>0;j-=a[o])
			if(a[j]>a[o]&&!c[j])c[o]=1;
	}
	for(int i=1;i<=n;i++)
		printf(c[i]?"A":"B");
}