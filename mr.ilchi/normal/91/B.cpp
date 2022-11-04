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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN= 1000*1000 + 5;

int n;
int mini[maxN] , val[maxN], res[maxN];
pii a[maxN];

inline int find (int s, int e, int cost){
	
	int res=-1;

	while (s<=e){
		
		int mid= (s+e)/2;

		if (mini[mid]<cost){
			res=mid;
			s=mid+1;
		}

		else
			e=mid-1;
	}
	
	return res;

}
/****************************/
int main(){
	scanf ("%d", &n);
	for (int i=1;i<=n;i++){
		scanf ("%d", &a[i].first);
		a[i].second=i;
	}

	sort (a+1 , a+n+1);

	int now=0;

	for (int i=1; i<=n; ){
		
		int j=i;

		while (j<=n && a[i].first==a[j].first) j++;

		while (i<j) { val[a[i].second]= now; i++; }

		now++;
	}

	mini[n+1]= val[n];

	for (int i=n; i!=0; i--){

		int pos= find (i+1,n,val[i]);

		if (pos==-1)
			res[i]= -1;

		else
			res[i]= pos-i-1;

		mini[i]= min (mini[i+1] , val[i]);
	}

	for (int i=1;i<=n;i++)
		printf ("%d ", res[i]);
	printf ("\n");

	return 0;
}