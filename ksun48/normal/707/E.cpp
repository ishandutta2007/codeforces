#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXF 2048
LL BIT[MAXF][MAXF];

void upd2(int x, int y, LL v){
	if(x == 0 || y == 0) return;
	LL c = x;
	while(c < MAXF){
		int d = y;
		while(d	< MAXF){
			BIT[c][d] += v;
			d += d & -d;
		}
		c += c & -c;
	}	
}

LL q2(int x, int y){
	if(x == 0 || y == 0) return 0;
	int c = x;
	LL a = 0;
	while(c > 0){
		int d = y;
		while(d	> 0){
			a += BIT[c][d];
			d -= d & -d;
		}
		c -= c & -c;
	}
	return a;
}


int n, m, k;
vector<int> st[2100]; // switch time
vector<int> ask; // ask time
vector<int> x1, x2, yy1, y2;
vector<LL> ans(2100);

int len[2100];
vector<int> x[2100];
vector<int> y[2100];
vector<int> w[2100];
int q;
int main(){
	for(int i = 0; i < MAXF; i++) for(int j = 0; j < MAXF; j++) BIT[i][j] = 0;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++){
		scanf("%d", &len[i]);
		for(int c = 0; c < len[i]; c++){
			int r, s, t;
			scanf("%d%d%d", &r, &s, &t);
			x[i].push_back(r);
			y[i].push_back(s);
			w[i].push_back(t);
		}
	}
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		char stuff[10];
		scanf("%s", stuff);
		if(stuff[0] == 'S'){
			int v;
			scanf("%d", &v);
			st[v-1].push_back(i);
		} else {
			ask.push_back(i);
			int xa, xb, ya, yb;
			scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
			x1.push_back(xa);
			x2.push_back(xb);
			yy1.push_back(ya);
			y2.push_back(yb);
		}
	}
	for(int i = 0; i < k; i++){
		int a = 0;
		int b = 0;
		int on = 1;
		for(int j = 0; j < w[i].size(); j++){
			upd2(x[i][j], y[i][j], w[i][j]);
		}
		while(b < ask.size()){
			if(a == st[i].size() || ask[b] < st[i][a]){
				if(on){
					ans[b] += q2(x2[b],y2[b])-q2(x1[b]-1,y2[b])-q2(x2[b],yy1[b]-1)+q2(x1[b]-1,yy1[b]-1);
				}
				b++;
			} else {
				on = 1 - on;
				a++;
			}
		}
		for(int j = 0; j < w[i].size(); j++){
			upd2(x[i][j], y[i][j], -w[i][j]);
		}
	}
	for(int i = 0; i < ask.size(); i++){
		printf("%I64d\n", ans[i]);
	}
}