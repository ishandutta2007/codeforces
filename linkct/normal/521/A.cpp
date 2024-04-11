#include <cstdio>
typedef long long int ll;
const int MAXN = 100005;
const ll MOD = 1000000007LL;

int len, cnt[5], cntt, maxt = -1;
char str[MAXN];

int main(){
	int ans = 1, i;
	scanf("%d%s", &len, str + 1);
	for(i = 1; i <= len; ++ i)
		switch(str[i]){
			case 'A': cnt[1] ++; break;
			case 'T': cnt[2] ++; break;
			case 'G': cnt[3] ++; break;
			case 'C': cnt[4] ++; break;
		}
	for(i = 1; i <= 4; ++ i)
		if(cnt[i] > maxt) maxt = cnt[i], cntt = 1;
		else if(cnt[i] == maxt) cntt ++;
	for(i = 1; i <= len; ++ i)
		ans = (int)(((ll)ans * cntt) % MOD);
	printf("%d\n", ans);
	return 0;
}