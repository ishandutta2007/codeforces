#include<stdio.h>

int L[333333 * 19], R[333333 * 19], Z, CT[333333 * 19];

int tmp[19];
void ins(int x){
	int p = 1;
	CT[0] = 0;
	for(int i=18; i>=0; i--){
		tmp[i] = p;
		if(x&(1<<i)){
			if(R[p] == 0){
				R[p] = ++Z;
			}
			p = R[p];
		}else{
			if(L[p] == 0)
				L[p] = ++Z;
			p = L[p];
		}
	}
	CT[p] = 1;
	for(int i=0; i<=18; i++){
		p = tmp[i];
		CT[p] = CT[L[p]] + CT[R[p]];
	}
}
int query(int x){
	int p = 1,res = 0;
	for(int i=18; i>=0; i--)
		if((x&(1<<i)) == 0){
			if(L[p] == 0 || CT[L[p]] < (1<<i)){
				if(L[p] == 0)break;
				p = L[p];
			}else{
				res += 1<<i;
				if(R[p] == 0)break;
				p = R[p];
			}
		}else{
			if(R[p] == 0 || CT[R[p]] < (1<<i)){
				if(R[p] == 0)break;
				p = R[p];
			}else{
				res += 1<<i;
				if(L[p] == 0)break;
				p = L[p];
			}
		}
	return res;
}

int main(){
	int n,m,x,r=0;
	Z = 1;
	for(scanf("%d%d",&n,&m); n--;){
		scanf("%d",&x);
		ins(x);
	}
	while(m--){
		scanf("%d",&x);
		r^=x;
		printf("%d\n",query(r));
	}
	return 0;
}