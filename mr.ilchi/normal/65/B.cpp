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
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int maxN= 1000+5;

int n;
string a[maxN];
vector <string> Q[maxN];

inline void All (string v, int id){
	if (v[0]>'2'){
		v[0]='1';
		Q[id].push_back (v);
		v[0]='2';
		if (v<="2011"){
			Q[id].push_back (v);
		}	
		return;
	}
	if (v[0]=='1'){
		for (int i=1;i<4;i++){
			char tmp= v[i];
			for (char j='0'; j<='9' ; j++) if (j!=tmp){
				v[i]= j;
				Q[id].push_back (v);
			}
			v[i]= tmp;
		}
		Q[id].push_back (v);
		v[0]= '2';
		if (v<="2011")
			Q[id].push_back (v);
		return;
	}

	for (int i=1;i<4;i++){
		char tmp= v[i];
		for (int j='0';j<='9';j ++) if(j!=tmp){
			v[i]=j;
			if (v<="2011")
				Q[id].push_back (v);
		}
		v[i]= tmp;
	}
	if (v<="2011")
		Q[id].push_back (v);

	v[0]= '1';
	Q[id].push_back (v);
}
/********************************/
int main(){
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	for (int i=1;i<=n;i ++){
		All (a[i],i);
		sort (Q[i].begin(), Q[i].end());
	}

	string past= "";

	vector <string> res;
	for (int i=1;i<=n;i ++){
		for (int j=0;j< (int)Q[i].size();j ++){
			if (past<=Q[i][j]){
				past= Q[i][j];
				res.push_back (Q[i][j]);
				break;
			}	
		}
	}

	if ((int)res.size()!=n)
		cout << "No solution" << endl;
	else{
		for (int i=0;i<n;i ++)
			cout << res[i] << endl;
	}
	return 0;
}