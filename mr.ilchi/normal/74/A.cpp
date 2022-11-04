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
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int maxN= 50 + 5;

int n;
int score[maxN];
string name[maxN];

int main(){
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> name[i];
		int plus, mines, a,b,c,d,e;

		cin >> plus >> mines >> a >> b >> c >> d >> e;

		score[i]+= plus*100 - mines*50 + a+b+c+d+e;
	}

	int maxPos= 1;

	for (int i=2;i<=n;i++) if (score[maxPos] < score[i])
		maxPos= i;

	cout << name[maxPos] << endl;

	return 0;
}