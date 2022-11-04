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
 */

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int INF= 1000*1000*1000;
const int MAXN= 20+5;

char mat[MAXN][MAXN];
int n, m;
int cnt, res= INF, rx, ry;

inline void check (int X, int Y){
	map <string, bool> mark;

	for (int i= 1;i<= n;i+= X){
		for (int j= 1;j<= m;j+= Y){
			string tmp;
			for (int ii= i, leni= i+X;ii < leni;ii ++){
				for (int jj= j, lenj= j+Y;jj < lenj;jj ++)
					tmp+= mat[ii][jj];
			}
			if (mark[tmp])
				return;
			mark[tmp]= true;
			reverse (tmp.begin (), tmp.end ());
			mark[tmp]= true;
			if (X== Y){
				string temp;
				for (int jj= j, lenj= j+Y;jj < lenj;jj ++)
					for (int ii= i+X-1;ii>= i;ii --)
						temp+= mat[ii][jj];
				mark[temp]= true;
				reverse (temp.begin (), temp.end ());
				mark[temp]= true;
			}	
		}
	}	
	cnt ++;
	if (X*Y < res){
		res= X*Y;
		rx= X, ry= Y;
	}	
}
/********************************/
int main (){
	cin >> n >> m;
	for (int i= 1;i<= n;i ++)
		for (int j= 1;j<= m;j ++)
			cin >> mat[i][j];

	for (int i= 1;i<= n;i ++)
		for (int j= 1;j<= m;j ++)
			if (n%i== 0 && m%j== 0)
				check (i, j);

	cout << cnt << endl << rx << ' ' << ry << endl;
	
	return 0;
}