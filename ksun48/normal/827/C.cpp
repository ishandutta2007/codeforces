#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

char str[110000];

const int maxn = 110000;
int t[maxn][4][11];

void add(int i, int value, int let) {
	for(int j = 1; j <= 10; j++){
		int c = i/j;
		int d = i%j;
		for (; c*j+d < maxn; c += ((c + 1) & -(c + 1))){
			//cout << c*j+d << " ";
			t[c*j+d][let][j] += value;
		}
		//cout << c*j+d << endl;
	}
}

// sum[0..i]
int sum(int i, int j, int let) {
	if(i < 0) return 0;
	int c = i/j;
	int d = i%j;
	int res = 0;
	//cout << i << " " << j << " : ";
	for (; c >= 0; c -= ((c + 1) & -(c + 1))){
		//cout << c << " ";
		res += t[c*j+d][let][j];
	}
	//cout << c << " ";
	//cout << endl;
	return res;
}
int d[26];

char e[12];
int main(){
	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 11; k++){
				t[i][j][k] = 0;
			}
		}
	}
	d['A'-'A'] = 0; d['C'-'A'] = 1; d['G'-'A'] = 2; d['T'-'A'] = 3; 
	int q;
	scanf("%s", str);
	scanf("%d", &q);
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		add(i,1,d[str[i]-'A']);
	}
	for(int v = 0; v < q; v++){
		int a;
		scanf("%d", &a);
		if(a == 1){
			int x;
			scanf("%d%s", &x, e);
			x--;
			add(x,-1,d[str[x]-'A']);
			str[x] = e[0];			
			add(x,1,d[str[x]-'A']);		
		} else {
			int l, r;
			scanf("%d%d%s", &l, &r, e);
			l--;
			r--;
			int ans = 0;
			int cur = strlen(e);
			for(int i = 0; i < cur; i++){
				int a1 = sum(r-i, cur,d[e[ (r-i-l + 2*cur) % cur]-'A']);
				//cout << r-i << " " << e[ (r-i-l + 2*cur) % cur] << " " << a1 << endl;
				int a2 = sum(l-1-i,cur,d[e[ (l-1-i-l + 2*cur) % cur]-'A']);
				//cout << l-1-i << " " << e[ (l-1-i-l + 2*cur) % cur] << " " << a2 << endl;
				ans += a1 - a2;
			}
			printf("%d\n", ans);
		}
	}
}