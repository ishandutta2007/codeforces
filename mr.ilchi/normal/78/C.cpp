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
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int maxN= 100000 + 5;

int n,m,k;
int win[maxN];

int main(){
	
	cin >> n >> m >> k;

	vector <int> Q;

	for (int i=1;i*i<=m;i++) if (m%i==0){
		Q.push_back (m/i);
		if (i*i!=m)
			Q.push_back (i);
	}

	sort (Q.begin(), Q.end());

	for (int i=0;i<(int)Q.size();i++){
		
		if (Q[i]<=k){
			win[i]= 2;
			continue;
		}

		win[i]= 2;

		for (int j=0;j<i;j++) if (k<=Q[j] && Q[i]%Q[j]==0){
			
			if ((Q[i]/Q[j])%2==0 || win[j]==2){
				win[i]= 1;
				break;
			}
		}
	}

	if (n%2==0 || win[(int)Q.size()-1]==2)
		puts ("Marsel");
	else
		puts ("Timur");

	return 0;
}