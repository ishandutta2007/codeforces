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
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxN= 1000+5;
const int maxA= 100+5;

bool val[maxN][maxN];
char mat[maxN][maxN];
int a,b,c,d,n;
int x[maxN];

inline void Fill(){
	for (int i=1;i<=b;i ++)
		for (int j=1;j<=a;j ++)
			val[i][j]= true;

	for (int i=1;i<=d;i ++)
		for (int j=a+1;j<=a+c;j++)
			val[i][j]= true;

	int key;
	if (b>=d){
		key= (d&1) ? -1 : 1;
	}				

	else
		key= (b&1) ? 1 : -1;

	int poi=1;
	for (int i=1;i<=max(b,d);i++){
		if (key>0){
			for (int j=1, lenj= a+c;j<=lenj;j ++){
				if (val[i][j]){
					mat[i][j]= poi-1+'a';
					x[poi]--; 
					if (x[poi]==0)
						poi++;
				}
				else
					mat[i][j]= '.';
			}		
		}

		else{
			for (int j=a+c;j>0;j --){
				if (val[i][j]){
					mat[i][j]= poi-1+'a';
					x[poi]--;
					if (x[poi]==0)
						poi++;
				}
				else
					mat[i][j]= '.';
			}
		}

		key= -key;
	}
}
/*******************************/
int main(){
	cout << "YES" << endl; 
	cin >> a >> b >> c >> d >> n;
	for (int i=1;i<=n;i++)
		cin >> x[i];

	Fill();
	
	for (int i=1;i<=max(b,d);i ++, cout << endl)
		for (int j=1;j<=a+c;j ++)
			cout << mat[i][j];

	return 0;
}