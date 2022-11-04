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
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

const ll INF= (1ll<<60);

int n,m;

struct small{
	int tool;
	int a[5000 + 5];

	ll lr, rl, sum, dp;

	small(){
		sum=0;
		lr= rl= dp= -INF;
	}

	inline void read(){
		scanf ("%d", &tool);
		
		for (int i=1;i<=tool;i++){
			scanf ("%d", &a[i]);
			sum+= a[i];
		}

		ll cur=0;
		for (int i=1;i<=tool;i++){
			cur+= a[i];
			lr  = max (lr, cur); 
		}

		cur=0;

		for (int i=tool;i>=0;i--){
			cur+= a[i];
			rl= max (rl, cur);
		}

		cur=0;

		for (int i=1;i<=tool;i++){
			dp = max (dp, cur + a[i]);
			cur= max (0ll, cur+a[i]);  
		}
	}

}sm[100];
/**********************************/
int main(){
	scanf ("%d%d", &n, &m);

	for (int i=1;i<=n;i++)
		sm[i].read();

	ll res=-INF;
	
	ll cur= 0;

	for (int i=1;i<=m;i++){
		int pos; scanf ("%d", &pos);

		res= max (res, max(max(sm[pos].lr,sm[pos].sum) + cur, sm[pos].rl));

		cur= max (0ll, max(cur + sm[pos].sum , sm[pos].rl)); 

		res= max (res, sm[pos].dp);
	}

	cout << res << endl;

	return 0;
}