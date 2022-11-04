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

using namespace std;

const int MAXN= 1000+5;

bool flag[MAXN];
bool mark[MAXN][MAXN];
int n;

int main (){
	cin >> n;
	int p= 0;
	flag[p]= true;
	for (int i= 1;true;i ++){
		int tmp= (p+i)%n;
		if (mark[p][tmp])
			break;
		mark[p][tmp]= flag[tmp]= true;
		p= tmp;
	}		
	for (int i= 0;i< n;i ++)
		if (!flag[i]){
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	
	return 0;
}