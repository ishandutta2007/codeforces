#include<cstdio>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		if(r/2+1>=l)printf("%d\n",r-r/2-1);
		else printf("%d\n",r%l);
	}
}