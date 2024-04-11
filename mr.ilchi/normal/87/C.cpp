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
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN= 100*1000 + 5;
const int maxL= 2000;

int n;
int dp[maxN], XOR[maxN], mark[maxL];

int main(){

	cin >> n;

	dp[1]= dp[2]= 0;

	int tedad=0;

	for (int i=3;i<=n;i++){

		tedad++;

		for (int j=2; true; j++){
			
			int cnt= (j*(j+1))/2;

			if (i < cnt) break;

			if (((i-cnt)%j)!=0) continue;

			int beg= 1+(i-cnt)/j;
			int end= beg  + j-1;

			int tmp= (XOR[end]^XOR[beg-1]);

			if (i==n && tmp==0){
				cout << j << endl;
				return 0;
			}

			if (tmp < maxL)
				mark[tmp]= tedad;			
		}

		for (int j=0; true; j++) if (mark[j]!=tedad) {dp[i]=j; break;}

		XOR[i]= (XOR[i-1]^dp[i]);
	}

	cout << -1 << endl;

	return 0;
}