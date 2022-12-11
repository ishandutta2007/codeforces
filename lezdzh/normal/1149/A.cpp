#include<cstdio>
#include<algorithm>
using namespace std;

int b[400001],p[400001];
int main(){
	b[1]=1;
	for(int i=2;i<=400000;i++){
		if(!b[i])p[++p[0]]=i;
		for(int j=1;i*p[j]<=400000;j++){
			b[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	int n;
	scanf("%d",&n);
	int s=0,k=0,w=0;
	for(int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		s+=o;
		k+=o==2;
		w+=o==1;
	}
	for(int i=0;;){
		if(!b[i+1])if(w)w--,printf("%d ",1),i++;
			else k--,printf("%d ",2),i+=2;
		else if(k)k--,printf("%d ",2),i+=2;
			else w--,printf("%d ",1),i++;
		if(!k&&!w){
			printf("\n");
			break;
		}
	}
}