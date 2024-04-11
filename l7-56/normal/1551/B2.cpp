#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n,k,T,top;
map <int, int> cnt;

struct node{
	int val,id,ans;
}a[maxn];

bool cmp(node x, node y){
	return x.val < y.val;
}

bool cmp2(node x, node y){
	return x.id < y.id;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i].val), a[i].id = i, cnt[a[i].val] = min(k, cnt[a[i].val] + 1), a[i].ans = 0;
		sort(a + 1, a + n + 1, cmp);
		top = 0;
		for(int i = 1; i <= n; ++i){
			if(cnt[a[i].val] == 0) continue;
			cnt[a[i].val]--;
			a[i].ans = ++top;
			top %= k;
		}
		if(top){
			for(int i = n; i >= 1 && top; --i){
				if(a[i].ans) a[i].ans = 0,--top;
				if(top == 0) break;
			}
		}
		sort(a + 1, a + n + 1, cmp2);
		for(int i = 1; i <= n; ++i)
			printf("%d ", a[i].ans);
		putchar('\n');
	}
	return 0;
}