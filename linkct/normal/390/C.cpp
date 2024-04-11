#include <cstdio>
#define MAX 100005

int bit[10][MAX], n, k, w, len;

inline void update(int bit[], int pos){
	for(; pos <= len; pos += pos & (-pos))
		bit[pos] ++;
}
inline int query(int bit[], int pos){
	int retval = 0;
	for(; pos; pos -= pos & (-pos))
		retval += bit[pos];
	return retval;
}
int main(){
	int i, j, l, r, ans;
	scanf("%d%d%d", &n, &k, &w);
	len = (n - 1) / k + 1;
	getchar();
	for(i = 0; i < n; ++ i)
		if(getchar() - '0')
			update(bit[i % k], (i / k) + 1);
	for(i = 1; i <= w; ++ i){
		scanf("%d%d", &l, &r);
		l --, r --;
		ans = ((r - l + 1) / k) - (query(bit[r % k], (r / k) + 1) - query(bit[r % k], ((l + k - 1) / k)));
		for(j = 0; j < k - 1; ++ j)
			ans += query(bit[(l + j) % k], (r + j + 1) / k) - query(bit[(l + j) % k], (l + j) / k);
		printf("%d\n", ans);
	}
	return 0;
}