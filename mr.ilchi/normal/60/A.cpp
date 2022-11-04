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
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int maxN= 1000+5;

bool mark[maxN];
int n,m;
string s;

int main(){
	cin >> n >> m;
	int beg=1, fin=n;
	for (int i=1;i<=m;i ++){
		cin >> s >> s >> s;
		int id= 0;
		int type= (s[0]=='r') ? 0 : 1;
		cin >> s >> s;
		for (int j=0;j< (int)s.size();j ++)
			id= id*10 + (s[j]-'0');
		if (type==1){
			if (id<=beg){
				cout << -1 << endl;
				return 0;
			}
			fin= min (fin, id-1);
		}
		if (type==0){
			if (fin<=id){
				cout << -1 << endl;
				return 0;
			}
			beg= max (beg, id+1);
		}
	}

	cout << fin-beg+1 << endl;	

	return 0;
}