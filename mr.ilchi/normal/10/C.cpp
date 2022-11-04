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

#include <cstdio>

typedef long long ll;

int n;

inline ll amount (int v){
	if (v== 0)
		return n/9;
	return n/9+ (v<=(n%9));
}	
/*******************************/
int main (){
	scanf ("%d", &n);
	
	ll res= 0;
	for (int i= 1;i<= 9;i ++)
		for (int j= 1;j<= 9;j ++)
			res+= amount(i)* amount(j)* amount((i*j)%9);

	for (int i= 1;i<= n;i ++)
		res-= (n/i);

	printf ("%I64d\n", res);
	
	return 0;
}