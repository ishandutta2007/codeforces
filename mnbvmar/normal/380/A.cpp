#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;


const int MAX = 100005;

LL begins[MAX], len[MAX];
int n, q, t, x, l, c, nbeg;

map<LL,int> Ins;
int tbl[MAX], num;
LL pos;


int main(){
	num = pos = nbeg = 0;
	scanf("%d", &q);
	
	while(q--){
		scanf("%d", &x);
		if(x == 1){
			scanf("%d", &x);
			if(num < MAX) tbl[num++] = x;
			
			Ins[pos] = x;
			pos++;
		} else {
			scanf("%d%d", &l, &c);
			
			int added = 0;
			
			while(num < MAX && added < l*c){
				tbl[num++] = tbl[added%l]; added++;
			}
			begins[nbeg] = pos;
			len[nbeg] = l;
			nbeg++;
			
			pos += l*c;
		}
	}
	//printf("Y\n");
	
	begins[nbeg] = 1212121212LL * 1212121212;
	
	scanf("%d", &n);
	
	//chg!
	for(int i = 0; i < n; i++){
		LL el;
		scanf("%I64d", &el);
		el--;
		
		if(Ins.find(el)!=Ins.end()){
			printf("%d ", Ins[el]); continue;
		}
		
		int pos = upper_bound(begins, begins+nbeg+1, el)-begins-1;
		//printf(">> %lld %d, %lld %lld %lld\n", el, pos, begins[pos], len[pos],
		//     (el-begins[pos])%len[pos]);
		
		printf("%d ", tbl[(el-begins[pos])%len[pos]]);
	}
	printf("\n");
}