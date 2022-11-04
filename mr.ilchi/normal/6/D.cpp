/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>

using namespace std;

const int MAXN= 10+5;

int n, a, b;
int h[MAXN], cnt[MAXN], r_cnt[MAXN];
int res= 1000;

inline void solve (int v){
	if (v== n){
		int r= 0;
		for (int i= 2;i< n;i ++)
			r+= cnt[i];
		if (r < res){
			res= r;
			for (int i= 2;i< n;i ++)
				r_cnt[i]= cnt[i];
		}
		return;
	}
	int tmp_cnt= cnt[v];
	int inc= (max (-1, h[v-1])+b)/b;
	cnt[v]+= inc;
	h[v]-= inc*a, h[v+1]-= inc*b;
	solve (v+1);
	while (h[v]>= 0){
		cnt[v] ++;
		h[v]-= a, h[v+1]-= b;
		solve (v+1);
	}
	int diff= cnt[v]-tmp_cnt;
	h[v]+= diff*a, h[v+1]+= diff*b;
	cnt[v]= tmp_cnt;
}
/**************************************/
int main (){
	cin >> n >> a >> b;
	for (int i= 1;i<= n;i ++)
		cin >> h[i];
	
	while (h[1]>= 0){
		cnt[2] ++;
		h[1]-= b, h[3]-= b;
		h[2]-= a;
	}
	while (h[n]>= 0){
		cnt[n-1] ++;
		h[n-2]-= b, h[n]-= b;
		h[n-1]-= a;
	}	
	solve (2);
	cout << res << endl;
	for (int i= 2;i< n;i ++)
		for (int j= 1;j<= r_cnt[i];j ++)
			cout << i << ' ';
	cout << endl;

	return 0;
}