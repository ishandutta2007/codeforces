#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,s;
int d[502][5005];
int p10[502 * 5005];
queue<pair<int,int> > q;
int main(){
	scanf("%d%d",&n,&s);
	memset(d,-1,sizeof(d));
	d[0][0] = 0;
	q.push(make_pair(0,0));
	while(!q.empty()){
		int rem = q.front().first;
		int sum = q.front().second;
		q.pop();
		for(int i=0; i<10; i++){
			int cur_rem = (rem * 10 + i) % n;
			int cur_sum = sum + i;
			if(cur_sum <= s && d[cur_rem][cur_sum] == -1){
				d[cur_rem][cur_sum] = d[rem][sum] + 1;
				q.push(make_pair(cur_rem, cur_sum));
			}
		}
	}
	if(d[0][s] == -1){
		puts("-1");
		return 0;
	}
	p10[0] = 1;
	for(int i=1; i<502 * 5005; i++)p10[i] = p10[i-1] * 10 % n;
	int L = d[0][s], rem = 0, sum = s;
	while(L > 0){
		for(int i=1; i<10 && i <= sum; i++){
			int curL = d[(rem - p10[L-1] * i % n+ n)%n][sum - i];
			if(curL != -1 && curL < L){
				putchar(i + '0');
				rem = (rem - p10[L - 1] * i % n + n) % n;
				sum -= i;
				--L;
				while(L > curL){
					putchar('0');
					--L;
				}
				break;
			}
		}
	}
	puts("");
	return 0;
}