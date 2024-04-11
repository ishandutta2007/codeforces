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
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pair;

const int maxN= 1000+5;

int n;
int a[maxN];

inline int check(int pos){
	int ret=1;
	for (int i=pos-1;i>0;i--)
		if(a[i]<=a[i+1])
			ret++;
		else
			break;
	for (int i=pos+1;i<=n;i++)
		if(a[i]<=a[i-1])
			ret++;
		else
			break;

	return ret;
}
/***********************************/
int main(){
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i];

	int res=-1;
	for (int i=1;i<=n;i++)
		res= max(res,check(i));

	cout << res << endl;

	return 0;
}