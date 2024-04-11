#include <cstdio>
#include <ctime>
typedef long long int ll;
const int MAX = 1200001;

bool isComp[MAX];
int prime[MAX], primeSum[MAX], palinSum[MAX];

int isPalin(int x){
	int buf[20], len = 0, i;
	while(x) buf[++ len] = x % 10, x /= 10;
	for(i = 1; i <= len / 2; ++ i) if(buf[i] != buf[len - i + 1]) return 0;
	return 1;
}
int main(){
	int i, j; ll p, q;
	for(i = 2; i < MAX; ++ i){
		if(!isComp[i]) prime[++ prime[0]] = i;
		for(j = 1; i * prime[j] < MAX; ++ j){
			isComp[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	for(i = 2; i < MAX; ++ i) primeSum[i] = primeSum[i - 1] + int(!isComp[i]);
	for(i = 1; i < MAX; ++ i) palinSum[i] = palinSum[i - 1] + isPalin(i);
	scanf("%I64d%I64d", &p, &q);
	for(i = MAX - 1; i; -- i) if(q * primeSum[i] <= p * palinSum[i]) break;
	printf("%d\n", i);
	return 0;
}