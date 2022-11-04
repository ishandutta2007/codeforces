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
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

int n,t;
int a[1<<20];

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		int tmp; scanf("%d", &tmp);
		a[tmp-1] = -a[tmp-1];
	}
	stack<int> st;
	for (int i=n-1; i>=0; i--){
		if (a[i]>0 && !st.empty() && a[st.top()] == a[i]){
			a[st.top()]*=-1;
			st.pop();
		}else{
			if (a[i] < 0) a[i] = -a[i];
			st.push(i);
		}
	}
	if (!st.empty()){
		printf("NO\n");
		return 0;
	}
	puts("YES");
	for (int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}