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

const int maxN= 100*1000+5;

bool mark[maxN];
int n;
int a[maxN], b[maxN];
int test[2*maxN], Q[2*maxN], mini[2*maxN];
ll sum[2*maxN];

inline void check(int key){
	for (int i=n+1,leni=2*n; i<=leni; i++)
		test[i]= test[i-n];

	int N= 2*n;
	for (int i=1;i<=N;i++)
		sum[i]= test[i] + sum[i-1];

	int head=1, tail=1;
	for (int i=1;i<n;i++){
		while (head<tail && sum[i]<=sum[Q[tail-1]])
			tail--;
		Q[tail++]= i;
	}	

	for (int i=n;i<=N;i++){
		if (Q[head]<=(i-n))
			head++;
		while(head<tail && sum[i]<=sum[Q[tail-1]])
			tail--;
		Q[tail++]=i;
		mini[i-n+1]= Q[head];
	}

	if (key== 1){
		for (int i=1;i<=n;i++)
			if ((sum[mini[i]]-sum[i-1])>=0)
				mark[i]= true;
	}

	if (key==-1){
		for (int i=1;i<=n;i++)
			if ((sum[mini[i]]-sum[i-1])>=0)
				mark[n-i+1]= true;
	}

}
/*******************************/
inline void Clock(){
	for (int i=1;i<=n;i++)
		test[i]= a[i]-b[i];
	check(1);
}
/*******************************/
inline void declock(){
	test[1]= a[1]-b[n];
	for (int i=2;i<=n;i++){
		test[i]= a[i]-b[i-1];
	}
	reverse (test+1, test+n+1);
	check(-1);
}	
/*******************************/
int main(){
	scanf ("%d", &n);
	for (int i=1;i<=n;i++)
		scanf ("%d", &a[i]);
	for (int i=1;i<=n;i++)
		scanf ("%d", &b[i]);

	if (n==1){
		cout << 1 << endl << 1 << endl;
		return 0;
	}

	Clock();
	declock();

	int cnt=0;
	for (int i=1;i<=n;i++) if(mark[i])
		cnt++;

	printf ("%d\n", cnt);
	for (int i=1;i<=n;i++) if (mark[i])
		printf ("%d ", i);
	printf ("\n");
		
	return 0;
}