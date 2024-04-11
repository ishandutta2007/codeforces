#include <bits/stdc++.h>
#define MAXN 400000
using namespace std;
typedef long long LL;
// 1D BIT
int BIT[MAXN];
void upd(int x, int v){
	int c = x;
	while(c < MAXN){
		BIT[c] += v;
		c += c & -c;
	}	
}

int qu(int x){
	int c = x;
	int a = 0;
	while(c > 0){
		a += BIT[c];
		c -= c & -c;
	}
	return a;
}
int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	int p[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
		p[i]--;
	}
	int xa[q], xb[q], ya[q], yb[q];
	for(int i = 0; i < q; i++){
		scanf("%d%d%d%d", &ya[i], &xa[i], &yb[i], &xb[i]);
		ya[i]--; xa[i]--; yb[i]--; xb[i]--;
	}
	LL ans[q];
	for(int i = 0; i < q; i++){
		LL ln = n;
		ans[i] = ln*(ln-1)/2;
		LL c1 = xa[i];
		LL c2 = ya[i];
		LL c3 = n - xb[i] - 1;
		LL c4 = n - yb[i] - 1;
		ans[i] -= c1*(c1-1)/2;
		ans[i] -= c2*(c2-1)/2;
		ans[i] -= c3*(c3-1)/2;
		ans[i] -= c4*(c4-1)/2;
		//cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
	}
	vector<pair<int,int> > ysort;
	for(int i = 0; i < q; i++){
		ysort.push_back(make_pair(ya[i],i));
	}
	sort(ysort.begin(), ysort.end());
	int z = 0;
	for(int i = 0; i < MAXN; i++) BIT[i] = 0;
	for(int i = 0; i < n; i++){

		while(z < ysort.size() && ysort[z].first == i){
			int id = ysort[z].second;
			LL num1 = qu(xa[id]);
			LL num2 = qu(n) - qu(xb[id]+1);
			ans[id] += (num1)*(num1-1)/2;
			ans[id] += (num2)*(num2-1)/2;
			z++;
		}
		upd(p[i]+1,1);
	}

	ysort.clear();
	for(int i = 0; i < q; i++){
		ysort.push_back(make_pair(yb[i],i));
	}
	sort(ysort.begin(), ysort.end());
	reverse(ysort.begin(), ysort.end());

	z = 0;
	for(int i = 0; i < MAXN; i++) BIT[i] = 0;
	for(int i = n-1; i >= 0; i--){

		while(z < ysort.size() && ysort[z].first == i){
			int id = ysort[z].second;
			LL num1 = qu(xa[id]);
			LL num2 = qu(n) - qu(xb[id]+1);
			ans[id] += (num1)*(num1-1)/2;
			ans[id] += (num2)*(num2-1)/2;
			z++;
		}
		upd(p[i]+1,1);
	}
	for(int i = 0; i < q; i++){
		cout << ans[i] << endl;
	}
}