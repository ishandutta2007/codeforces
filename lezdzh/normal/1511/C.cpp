#include<cstdio>

using namespace std;

int p[51];
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		if(!p[o])p[o]=i;
	}
	for(int i=1;i<=q;i++){
		int o;
		scanf("%d",&o);
		printf("%d%c",p[o],i==q?'\n':' ');
		for(int j=1;j<=50;j++)
			if(p[j]&&p[j]<p[o])
				p[j]++;
		p[o]=1;
	}
}