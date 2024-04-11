#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int w=0;
	for(int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		o+=w;
		w=max(o,w);
		printf("%d%c",o,i==n?'\n':' ');
	}
}