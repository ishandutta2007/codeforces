#include<cstdio>
#include<algorithm>
using namespace std;
#define i64 long long int
#define ran 400040
int z;
i64 lst;
i64 wei[ran];

int dep[ran];
i64 mx[ran][19];
int fat[ran][19];

int len[ran];
i64 sum[ran][19];
int fat_sum[ran][19];

void make_mx(int x,int ff){
	fat[x][0] = ff;
	mx[x][0] = wei[ff];
	for(int i=1; (1<<i) <= dep[x]; i++){
		fat[x][i] = fat[fat[x][i-1]][i-1];
		mx[x][i] = max(mx[x][i-1], mx[fat[x][i-1]][i-1]);
	}
}
void make_sum(int x,int ff){
	fat_sum[x][0] = ff;
	len[x] = len[ff] + 1;
	sum[x][0] = wei[ff];
	for(int i=1; (1<<i) <= len[x]; i++){
		fat_sum[x][i] = fat_sum[fat_sum[x][i-1]][i-1];
		sum[x][i] = sum[x][i-1] + sum[fat_sum[x][i-1]][i-1];
	}
}

int main(){
	int q,t;
	z = 1;
	dep[1] = 0;
	wei[1] = 0;
	lst = 0;
	for(scanf("%d",&q); q--;){
		i64 P, Q;
		scanf("%d%I64d%I64d",&t,&P,&Q);
		int p = P ^ lst;
		i64 qq = Q ^ lst;
		if(t == 1){
			++z;
			dep[z] = dep[p] + 1;
			wei[z] = qq;
			make_mx(z, p);
			if(wei[z] <= wei[p])
				make_sum(z, p);
			else{
				int L = 0;
				while((1<<L) <= dep[p] && mx[p][L] < wei[z])L++; --L;
				for(int i=L; i>=0; i--)
					if((1<<i) <= dep[p] && mx[p][i] < wei[z])
						p = fat[p][i];
				if(p == 1){
					len[z] = 0;
				}else{
					make_sum(z, fat[p][0]);
				}
			}
		}else{
			if(qq < wei[p])
				lst = 0;
			else{
				qq -= wei[p];
				int L = 0;
				lst = 1;
				while((1<<L) <= len[p] && sum[p][L] <= qq)L++; --L;
				for(int i=L; i>=0; i--)
					if((1<<i) <= len[p] && sum[p][i] <= qq){
						lst += (i64)(1<<i);
						qq -= sum[p][i];
						p = fat_sum[p][i];
					}
			}
			printf("%I64d\n",lst);
		}
	}
	return 0;
}