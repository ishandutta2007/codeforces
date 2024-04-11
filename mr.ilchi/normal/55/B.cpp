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
 */

#include <iostream>
#include <algorithm>

using namespace std;

char c[10];
long long a[10];

int main (){
	for (int i= 1;i<= 4;i ++)
		cin >> a[i];
	for (int i= 1;i<= 3;i ++)
		cin >> c[i];

	sort (a+1, a+5);
	long long res= (1ll << 60);
	do{
		long long tmp= a[1];
		for (int i= 1;i<= 3;i ++)
			if (c[i]== '+')
				tmp+= a[i+1];
			else
				tmp*= a[i+1];
		res= min (res, tmp);
	}while (next_permutation (a+1, a+5));
	
	sort (a+1, a+5);
	do{
		long long tmp1, tmp2;
		if (c[1]== '+')	
			tmp1=a[1]+ a[2];
		else
			tmp1=a[1]* a[2];

		if (c[2]== '*')
			tmp2= a[3]* a[4];
		else
			tmp2= a[3]+ a[4];
		
		if (c[3]== '+')
			tmp1+= tmp2;
		else
			tmp1*= tmp2;
		res= min (res, tmp1);
		
	}while (next_permutation (a+1, a+5));
	
	cout << res << endl;

	return 0;
}