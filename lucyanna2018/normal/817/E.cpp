#include<stdio.h>
#define ran 2700000
const int magic = 27;
int p,z;
int sz[ran],lef[ran],rig[ran];
int main(){
	int q,t,x;
	z = 1;
	for(scanf("%d",&q); q--;){
		int t,x;
		scanf("%d%d",&t,&x);
		if(t == 1 || t == 2){
			int p = 1;
			for(int i=magic-1; i>=0; i--){
				if(x&(1<<i)){
					if(rig[p] == 0)rig[p] = ++z;
					p = rig[p];
				}else{
					if(lef[p] == 0)lef[p] = ++z;
					p = lef[p];
				}
				sz[p] += (t==2?-1:1);
			}
		}else{
			int y;
			scanf("%d",&y);
			int res = 0, p = 1;
			for(int i=magic-1; i>=0; i--){
				bool xi = (bool)(x&(1<<i));
				bool yi = (bool)(y&(1<<i));
				if(yi == 1){
					if(xi){
						if(rig[p] != 0)res += sz[rig[p]];
					}else{
						if(lef[p] != 0)res += sz[lef[p]];
					}
					xi = !xi;
				}
				if(xi){
					if(rig[p] == 0)break;
					p = rig[p];
				}else{
					if(lef[p] == 0)break;
					p = lef[p];
				}
			}
			printf("%d\n",res);
		}
	}
	return 0;
}