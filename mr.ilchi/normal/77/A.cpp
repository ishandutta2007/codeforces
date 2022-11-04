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
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

bool adj[10][10];
int a,b,c,e,diff= (1ll<<31)-1, doost=-1;
int test[10];
string name[]= {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
map <string, int> code;

inline void check (int p1, int p2){
	vector <int> h1,h2,h3;

	for (int i=0;i<=p1;i++)
		h1.push_back (test[i]);
	for (int i=p1+1;i<=p2;i++)
		h2.push_back (test[i]);
	for (int i=p2+1;i<7;i++)
		h3.push_back (test[i]);

	int sc[]= {a/h1.size(), b/h2.size(), c/h3.size()};
	int fr=0;

	sort (sc, sc+3);

	for (int i=0;i<(int)h1.size();i++)
		for (int j=0;j<(int)h1.size();j++)	
			fr+= adj[h1[i]][h1[j]];
	
	for (int i=0;i<(int)h2.size();i++)
		for (int j=0;j<(int)h2.size();j++)	
			fr+= adj[h2[i]][h2[j]];
	
	for (int i=0;i<(int)h3.size();i++)
		for (int j=0;j<(int)h3.size();j++)	
			fr+= adj[h3[i]][h3[j]];

	int tmp= sc[2]-sc[0];
	int maxi= fr;

	if ((tmp<diff) || (tmp==diff && maxi>doost)){
		diff= tmp;
		doost= maxi;
	}
}
/**********************************/
int main(){
	for (int i=0;i<7;i++)
		code[name[i]]= i;

	cin >> e;
	for (int i=1;i<=e;i++){
		string x,y; cin >> x >> y >> y;
		adj[code[x]][code[y]]= true;
	}

	cin >> a >> b >> c;

	for (int i=0;i<10;i++)
		test[i]= i;

	do{
		for (int i=0;i<5;i++){
			for (int j=i+1;j<6;j++){
				check(i,j);
			}
		}
	}while (next_permutation(test, test+7));
	
	cout << diff << ' ' << doost << endl;

	return 0;
}