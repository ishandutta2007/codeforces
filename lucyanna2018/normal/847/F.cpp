#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int N,K,M,A;
int cnt1[111],tim1[111];
int cnt[111],tim[111],id[111];
int res[111];
int B[111],LB;
bool cmp(int x,int y){
	if(cnt[x] != cnt[y])return cnt[x] > cnt[y];
	return tim[x] < tim[y];
}
void init(){
	for(int j=1; j<=N; j++){
		cnt[j] = cnt1[j];
		tim[j] = tim1[j];
		id[j] = j;
	}
}
int main(){
	scanf("%d%d%d%d",&N,&K,&M,&A);
	for(int i=1; i<=A; i++){
		int x;
		scanf("%d",&x);
		cnt1[x] ++;
		tim1[x] = i;
	}
	if(N == 1){
		res[1] = 1;
	}else
	if(A == M){
		init();
		sort(id+1, id+N+1, cmp);
		for(int j=1; j<=N; j++)
			res[id[j]] = j<=K && cnt[id[j]] != 0 ? 1 : 3;
	}else{
		for(int i=1; i<=N; i++){
			init();
			cnt[i] += M - A;
			tim[i] = M;
			sort(id+1,id+N+1, cmp);
			res[i] = 2;
			for(int j=1; j<=N; j++)
				if(id[j] == i){
					if(j>K){
						res[i] = 3;
					}
					break;
				}
			if(res[i] == 3)continue;
			init();
			if(cnt[i] == 0)continue;
			if(K == N){
				res[i] = 1;
				continue;
			}
			LB = 0;
			for(int j=1; j<=N; j++)if(j!=i){
				if(cnt[j] > cnt[i] || cnt[j] == cnt[i] && tim[j] < tim[i])
					B[LB++] = 0;
				else
					B[LB++] = cnt[i]-cnt[j]+1;
			}
			sort(B,B+LB);
			int total = 0;
			for(int j=0; j<K; j++)
				total += B[j];
			if(total <= M-A)
				res[i] = 2;
			else
				res[i] = 1;
		}
	}
	for(int j=1; j<=N; j++)
		printf("%d%c",res[j],j<N?' ':'\n');
	return 0;
}