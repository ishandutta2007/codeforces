#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int LL;

LL zz, zo, oz, oo, zcnt, ocnt;
char ans[1000005];

int main(){
	int i, j;
	scanf("%I64d%I64d%I64d%I64d", &zz, &zo, &oz, &oo);
	if(!oz && !zo && !zz && !oo){
		printf("0\n");
		return 0;
	}
	for(zcnt = 0; zcnt * (zcnt - 1) / 2 < zz; ++ zcnt)
		if(zcnt * (zcnt - 1) / 2 == zz) break;
	if(zcnt * (zcnt - 1) / 2 != zz){
		printf("Impossible\n");
		return 0;
	}
	for(ocnt = 0; ocnt * (ocnt - 1) / 2 < oo; ++ ocnt)
		if(ocnt * (ocnt - 1) / 2 == oo) break;
	if(ocnt * (ocnt - 1) / 2 != oo){
		printf("Impossible\n");
		return 0;
	}
	if(!zcnt && (oz || zo)) ++ zcnt;
	if(!ocnt && (oz || zo)) ++ ocnt;
	if((zcnt + ocnt) * (zcnt + ocnt - 1) / 2 != zz + zo + oz + oo){
		printf("Impossible\n");
		return 0;
	}
	if(!zcnt){
		if(zo || oz)
			printf("Impossible\n");
		else for(i = 1; i <= ocnt; ++ i)
			printf("1");
		return 0;
	}
	if(!zo){
		if(oz == ocnt * zcnt){
			for(i = 1; i <= ocnt; ++ i)
				putchar('1');
			for(i = 1; i <= zcnt; ++ i)
				putchar('0');
		}else printf("Impossible\n");
		return 0;
	}
	if((zo - 1) / zcnt + 1 > ocnt){
		printf("Impossible\n");
		return 0;
	}
	for(i = 1; i <= zo / zcnt; ++ i)
		ans[i] = '1';
	for(j = 1; j <= zcnt - (zo % zcnt); ++ i, ++ j)
		ans[i] = '0';
	if(zo % zcnt) ans[i ++] = '1';
	for(; j <= zcnt; ++ i, ++ j)
		ans[i] = '0';
	for(; i <= zcnt + ocnt; ++ i)
		ans[i] = '1';
	reverse(ans + 1, ans + 1 + ocnt + zcnt);
	printf("%s\n", ans + 1);
	return 0;
}