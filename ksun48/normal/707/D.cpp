#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> children[110000];

int book[1000][1000];
int rowsum[1000];
int ans[110000];
int flipped[110000];
int curans = 0;
int n, m, q;
int t[110000];
int a[110000];
int b[110000];
void solve(int q){
	ans[q] = curans;
	for(int z = 0; z < children[q].size(); z++){
		int did = 0;
		for(int rr = 0; rr < 2; rr++){
			int p = children[q][z];
			if(t[p] == 1){
				int i = a[p];
				int j = b[p];
				curans -= rowsum[i];
				rowsum[i] -= (book[i][j] != flipped[i]);
				if(rr == 0 && book[i][j] == flipped[i]){
					book[i][j] = 1-book[i][j];
					did = 1;
				}
				if(rr == 1 && did == 1){
					book[i][j] = 1-book[i][j];
				}
				rowsum[i] += (book[i][j] != flipped[i]);
				curans += rowsum[i];
			} else if(t[p] == 2){
				int i = a[p];
				int j = b[p];
				curans -= rowsum[i];
				rowsum[i] -= (book[i][j] != flipped[i]);
				if(rr == 0 && book[i][j] != flipped[i]){
					did = 1;
					book[i][j] = 1-book[i][j];
				}
				if(rr == 1 && did == 1){
					book[i][j] = 1-book[i][j];
				}
				rowsum[i] += (book[i][j] != flipped[i]);
				curans += rowsum[i];
			} else if(t[p] == 3){
				int i = a[p];
				curans -= rowsum[i];
				flipped[i] = 1-flipped[i];
				rowsum[i] = m-rowsum[i];
				curans += rowsum[i];
			}
			if(rr == 0) solve(p);
		}
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++){
			book[i][j] = 0;
		}
		flipped[i] = 0;
		rowsum[i] = 0;
	}
	for(int i = 1; i <= q; i++){
		scanf("%d", &t[i]);
		scanf("%d", &a[i]);
		if(t[i] == 1 || t[i] == 2) scanf("%d", &b[i]);
		if(t[i] != 4) a[i]--;
		if(t[i] == 1 || t[i] == 2) b[i]--;
		if(t[i] != 4){
			children[i-1].push_back(i);
		} else {
			children[a[i]].push_back(i);
		}
	}
	solve(0);
	for(int i = 1; i <= q; i++){
		printf("%d\n", ans[i]);
	}
}