#include <cstdio>

int tr[105], n, q;

int dfs(int dep, int cur){
	if(dep == n) return cur == 1;
	int i, ret = 0;
	if(!dep){
		for(i = 1; i <= 6; ++ i)
			ret += dfs(1, i);
	}else{
		for(i = 1; i <= 6; ++ i)
			if(tr[cur * 7 + i])
				ret += dfs(dep + 1, tr[cur * 7 + i]);
	}
	return ret;
}
int main(){
	int i; char buf1[5], buf2[5];
	scanf("%d%d", &n, &q);
	for(i = 1; i <= q; ++ i){
		scanf("%s%s", buf1, buf2);
		tr[(buf1[0] - 'a' + 1) * 7 + (buf1[1] - 'a' + 1)] = buf2[0] - 'a' + 1;
	}
	printf("%d\n", dfs(0, 0));
	return 0;
}