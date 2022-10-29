#include <cstdio>
#include <vector>
using namespace std;

int n;
int a[100005];
vector<int> sol[32];

int main(){
	int i,k,r;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",a+i);
	}
	for(k=0;k<32;++k){
		for(i=0;i<n;++i){
			if(((a[i])>>k)&1)
				sol[k].push_back(a[i]);
		}
	}
	for(k=31;k>=0;k--){
		r=-1;
		for(i=0;i<sol[k].size();++i){
			r &= sol[k][i];
		}
		if(r%(1<<k)==0)
			break;
	}
	printf("%d\n",sol[k].size());
	for(i=0;i<sol[k].size();++i){
		printf("%d ",sol[k][i]);
	}
	putchar('\n');
	return 0;
}