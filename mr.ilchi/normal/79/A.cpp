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
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int x,y;

int main(){
	
	cin >> x >> y;

	for (int i=1; true ; i++){
		
		if (i%2==1){

			if (x>=2){
				if (y<2){
					puts ("Hanako");
					return 0;
				}
				x-=2; y-=2;
			}

			else if (x==1){
				if (y<12){
					puts ("Hanako");
					return 0;
				}
				x--; y-=12;
			}

			else{
				if (y<22){
					puts ("Hanako");
					return 0;
				}
				y-=22;
			}
		}

		else{
			if (y>=22){
				y-=22;
			}

			else if (y>=12){
				if (x==0){
					puts ("Ciel");
					return 0;
				}
				x--; y-=12;
			}

			else if (y>=2){
				if (x<2){
					puts ("Ciel");
					return 0;
				}
				x-=2; y-=2;
			}
			else{
				puts ("Ciel");
				return 0;
			}
		}
	}

	return 0;
}