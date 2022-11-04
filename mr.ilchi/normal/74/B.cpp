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

using namespace std;

int n, st, co, direct;
string move;

int main(){
	cin >> n >> st >> co;
	cin >> move >> move;
	
	if (move=="head"){
		direct= -1;
		if (co==1){
			direct=1;
		}
	}
	else{
		direct= 1;
		if (co==n){
			direct=-1;
		}
	}

	cin >> move;

	for (int i=0;i<(int)move.size();i++){

		if (move[i]=='0'){
			if (direct==1){
				if (st==n && co==(n-1)){
					cout << "Controller "  << i+1 << endl;
					return 0;
				}

				if (st<co){
					st= max (st-1, 1);
				}	

				else{
					st= min (st+1, n);
				}

				co++;
				if (co==n)
					direct=-1;
			}

			else{
				if (st==1 && co==2){
					cout << "Controller "  << i+1 << endl;
					return 0;
				}

				if (st>co){
					st= min (st+1, n);
				}

				else{
					st= max (st-1, 1);
				}

				co--;

				if (co==1)
					direct=1;
			}
		}

		else{
			if (direct==1){
				co++;
				if (co==n)
					direct=-1;
				st=1;
			}

			else if (direct==-1){
				co--;
				if (co==1)
					direct=1;
				st=n;
			}
		}
	}

	cout << "Stowaway" << endl;

	return 0;
}