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

bool mark[10000+5];
int n;

inline void check (int num, int cpos, int cexi){
	int test[4];
	for (int i=0;i<4;i++){
		test[3-i]= num%10; num/=10;
	}

	int dig[4];
	for (int i=0;i<10000;i ++){
		if (mark[i])
			continue;
		int tmp=i;
		for (int j=0;j<4;j++){
			dig[3-j]= tmp%10; tmp/=10;
		}
		int pos=0, exi=0;
		for (int j=0;j<4;j++)
			pos+= (test[j]==dig[j]);

		for (int j=0;j<4;j++){
			for (int z=0;z<4;z++){
				if (test[j]==dig[z])
					exi++;
			}
		}

		exi-= pos;
		if (pos!=cpos || exi!=cexi)
			mark[i]= true;
	}
}
/************************************/
inline void init(){
	for (int i=0;i<10000;i ++){
		int test[4];
		int tmp=i;
		for (int j=0;j<4;j++){
			test[3-j]=tmp%10; tmp/=10;
		}
		sort (test, test+4);
		for (int j=0;j<3;j ++){
			if (test[j]==test[j+1]){
				mark[i]= true;
				break;
			}
		}
	}
}
/************************************/
int main(){
	cin >> n;
	init();
	for (int i=1;i<=n;i ++){
		int num, cpos, cexi;
		cin >> num >> cpos >> cexi;
		check (num, cpos, cexi);
	}

	int res=-1, cnt=0;
	for (int i=0;i<10000;i ++){
		if (!mark[i]){
			cnt++; res=i;
		}
	}

	if (cnt==0)
		cout << "Incorrect data" << endl;
	else if (cnt==1){
		if (res< 1000)
			cout << 0;
		cout << res << endl;
	}
	else
		cout << "Need more data" << endl;

	return 0;
}