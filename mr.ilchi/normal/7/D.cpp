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

using namespace std;

const int MAXN= 5*1000*1000+5;
const int MAXL= 3+2;
const int BASE= 128+3;

const int p[MAXL]= {1, 4583, 7853, 9091}; 

char dp[MAXN], s[MAXN];
int Pow[MAXL], rl[MAXL], lr[MAXL];

int main (){
	gets (s);
	int res= 1;
	dp[0]= 1;
	for (int i= 1;i<= 3;i ++)
		lr[i]= rl[i]= s[0];

	Pow[1]= Pow[2]= Pow[3]= 1;
	for (int i= 1;s[i]!= 0;i ++){
		for (int j= 1;j<= 3;j ++)
			Pow[j]= (Pow[j]*BASE)%p[j];
		for (int j= 1;j<= 3;j ++){
			lr[j]= (lr[j]*BASE+ s[i])%p[j];
			rl[j]= (rl[j]+ s[i]*Pow[j])%p[j];
		}
		for (int j= 1;j<= 3;j ++)
			if (lr[j]!= rl[j]){
				dp[i]= -1;
				break;
			}
		if (dp[i]== 0)
			dp[i]= dp[((i-1)>>1)]+ 1;
		else
			dp[i]= 0;
		res+= dp[i];
	}
	cout << res << endl;

	return 0;
}