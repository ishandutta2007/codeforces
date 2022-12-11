#include<cstdio>
#include<algorithm>
using namespace std;

int cpw;
int a[101][101],z[101],ok[101],l[101],r[101];
bool cmp(int i,int j){
	return a[i][cpw]<a[j][cpw];
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n*k;i++){
		int o;
		scanf("%d",&o);
		a[o][++a[o][0]]=i;
	}
	int w=(n+k-2)/(k-1);
	for(int i=1;i<k;i++){
		z[0]=0;
		cpw=i+1;
		for(int j=1;j<=n;j++)
			if(!ok[j])z[++z[0]]=j;
		sort(z+1,z+z[0]+1,cmp);
		for(int o=1;o<=min(w,z[0]);o++){
			l[z[o]]=a[z[o]][i];
			r[z[o]]=a[z[o]][i+1];
			ok[z[o]]=1;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",l[i],r[i]);
}