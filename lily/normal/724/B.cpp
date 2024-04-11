#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;


int n,m;
int a[25][25];

inline bool check() {
	for (int i=1;i<=n;i++) {
		int rec=0;
		for (int j=1;j<=m;j++) {
			if (a[i][j]!=j) {
				if (a[i][a[i][j]]==j && (!rec || rec==j)) {
					rec=a[i][j];
					continue;
				}
				else return 0;
			}
		}
	}
	return 1;
}


int main() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			cin>>a[i][j];
		}
	}
	if (check()) {puts("YES");return 0;}
	for (int i=1;i<m;i++)
		for (int j=i+1;j<=m;j++) {
			for (int k=1;k<=n;k++) {
				swap(a[k][i],a[k][j]);
			}
			if (check()) {puts("YES");return 0;}
			for (int k=1;k<=n;k++) {
				swap(a[k][i],a[k][j]);
			}
		}
	puts("NO");
	return 0;
}