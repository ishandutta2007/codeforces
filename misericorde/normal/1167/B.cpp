#include <bits/stdc++.h>

int d[60]={0,4,8,15,16,23,42},rank[100],ans[50],n;

int main() {
	for (int i=1;i<=4;++i) {
		
		printf("? %d %d\n",i,i+1);
		fflush(stdout);
		scanf("%d",&ans[i]);
	} for (int i=1;i<=6;++i) rank[i]=i;
	do {
		int flag=0;
		for (int i=1;i<=4;++i) {
			if (d[rank[i]]*d[rank[i+1]]!=ans[i]) {flag=1;break;}
		}if (!flag) {printf("! "); for (int i=1;i<=6;++i) printf("%d ",d[rank[i]]);
		printf("\n");fflush(stdout);return 0;}
	}while(std::next_permutation(rank+1,rank+6+1));
	return 0;
}