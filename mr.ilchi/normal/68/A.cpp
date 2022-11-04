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
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int a,b;
int p[10];
int cnt[50000];

int main(){
	for (int i=1;i<=4;i++)
		cin >> p[i];
	sort (p+1, p+5);

	cin >> a >> b;

	do{
		for (int i=a;i<=b;i++){
			int tmp= i;
			for (int j=1;j<=4;j++)
				tmp= (tmp%p[j]);
			if (tmp==i)
				cnt[i]++;
		}
	}while (next_permutation(p+1,p+5));

	int res=0;
	for (int i=a;i<=b;i++) if(cnt[i]>7)
		res++;

	cout << res << endl;

	return 0;
}