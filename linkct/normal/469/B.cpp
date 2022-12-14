#include <cstdio>

int p, q, l, r, left[55][2], right[55][2];

bool check(int delta){
	int pos0 = 1, pos1 = 1, i;
	bool avail[2] = {false, false};
	for(i = 0; i <= 1000; ++ i){
		if(left[pos0][0] == i) avail[0] = true, pos0 ++;
		if(left[pos1][1] + delta == i) avail[1] = true, pos1 ++;
		if(avail[0] && avail[1]) return true;
		if(right[pos0 - 1][0] == i) avail[0] = false;
		if(right[pos1 - 1][1] + delta == i) avail[1] = false;
	}
	return false;
}
int main(){
	int i, ans = 0;
	scanf("%d%d%d%d", &p, &q, &l, &r);
	for(i = 1; i <= p; ++ i)
		scanf("%d%d", &left[i][0], &right[i][0]);
	for(i = 1; i <= q; ++ i)
		scanf("%d%d", &left[i][1], &right[i][1]);
	for(i = l; i <= r; ++ i)
		if(check(i)) ans ++;
	printf("%d\n", ans);
	return 0;
}