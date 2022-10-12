#include<cstdio>
#define ran 1000010
int n;
char f[ran];int lef[ran], rig[ran];
int val[ran];
bool chgL[ran], chgR[ran];
bool res[ran];
void dfs1(int x) {
	if (f[x] == 'I') {
		val[x] = lef[x];
		return;
	}
	if (f[x] == 'N') {
		int y = lef[x];
		dfs1(y);
		val[x] = !val[y];
		chgL[x] = true;
		return;
	}
	int lc = lef[x], rc = rig[x];
	dfs1(lc);
	dfs1(rc);
	if (f[x] == 'A') {
		val[x] = (val[lc] & val[rc]);
		if (val[lc] == 1)chgR[x] = true;
		if (val[rc] == 1)chgL[x] = true;
	}else
	if(f[x] == 'O'){
		val[x] = (val[lc] | val[rc]);
		if (val[lc] == 0)chgR[x] = true;
		if (val[rc] == 0)chgL[x] = true;
	}
	else {
		val[x] = val[lc] ^ val[rc];
		chgL[x] = chgR[x] = true;
	}
}
void dfs2(int x) {
	if (f[x] == 'I')return;
	if (f[x] == 'N') {
		int y = lef[x];
		res[y] = res[x] && chgL[x];
		dfs2(y);
		return;
	}
	int lc = lef[x], rc = rig[x];
	res[lc] = res[x] && chgL[x];
	dfs2(lc);
	res[rc] = res[x] && chgR[x];
	dfs2(rc);
}
int main() {
	char s[9];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s%d", s, &lef[i]);
		f[i] = *s;
		if (f[i] != 'I' && f[i] != 'N')scanf("%d", &rig[i]);
	}
	dfs1(1);
	res[1] = true;
	dfs2(1);
	for (int i = 1; i <= n; i++)
		if (f[i] == 'I')putchar(val[1] ^ (int)res[i] ? '1' : '0');
	puts("");
	return 0;
}