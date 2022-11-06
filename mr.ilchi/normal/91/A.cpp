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
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int max1= 1000*10 + 5;
const int maxA= 26+5;

int nex[max1][maxA];
string s1,s2;

inline void setDyn(){
	
	for (int i=0; i<26;i++) nex[(int)s1.size()][i]= -1;

	for (int i=(int)s1.size()-1; i>=0; i--){
		int tmp=s1[i]-'a';
		for (int j=0; j<26; j++) 
			nex[i][j]= nex[i+1][j];
		nex[i][tmp]= i;
	}
}
/******************************/
int main(){
	
	getline (cin,s1);
	getline (cin,s2);

	setDyn();

	int now=0 , res=1;

	for (int i=0; i<(int)s2.size(); i++){

		int pos= nex[now][(int)s2[i]-'a'];

		if (pos!=-1){
			now = pos+1;
			if (now==(int)s1.size() && i!=(int)s2.size()-1){
				now=0;
				res++;
			}
		}

		else{
			if (nex[0][(int)s2[i]-'a']==-1){
				cout << -1 << endl;
				return 0;
			}

			res++;

			now= nex[0][(int)s2[i]-'a'] + 1;

			if (now==(int)s1.size() && i!=(int)s2.size()-1){
				now=0;
				res++;
			}
		}
	}

	cout << res << endl;

	return 0;
}