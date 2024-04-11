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
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int maxN= 5000 + 5;
const string M= "URDL";
const int opos[]= {2,3,0,1};

int n,m,cnt;
vector <char> mat[maxN];

struct node{
	pii a[4];

	node() {a[0]=a[1]=a[2]=a[3]=pii(-1,-1);}
};
vector <node> mov[maxN] , asl[maxN];
/*******************************/
inline void init (){
	
	for (int i=1;i<=n;i++){
		int past=-1;
		for (int j=1;j<=m;j++) if (mat[i][j]!='.'){
			if (past!=-1){ 
				asl[i][past].a[1]= pii(i,j); 
				asl[i][j].a[3]= pii(i,past);
			}
			past=j;
		}
	}

	for (int j=1;j<=m;j++){
		int past=-1;
		for (int i=1;i<=n;i++) if (mat[i][j]!='.'){
			if (past!=-1){
				asl[past][j].a[2]= pii(i,j);
				asl[i][j].a[0]= pii(past,j);
			}
			past=i;
		}
	}
}
/*******************************/
inline void SET (){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) if (mat[i][j]!='.')
			mov[i][j]= asl[i][j];
}
/*******************************/
inline void go (int x, int y){

	if (x==-1) return;

	cnt++;

	pii tmp;

	for (int i=0;i<4;i++) if ((tmp=mov[x][y].a[i])!=pii(-1,-1)){		
		mov[tmp.first][tmp.second].a[opos[i]]= mov[x][y].a[opos[i]];
	}

	int ind= M.find (mat[x][y]);

	go (mov[x][y].a[ind].first , mov[x][y].a[ind].second);
}
/*******************************/
int main(){
	
	cin >> n >> m;

	for (int i=1;i<=n;i++){
		mov[i].resize (m+1);
		mat[i].resize (m+1);
		asl[i].resize (m+1);
	}
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin >> mat[i][j];

	int maxi=-1, cmaxi=-1;
	
	init ();

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) if (mat[i][j]!='.'){
			
			SET ();
			cnt= 0; go(i,j);

			(maxi==cnt) ? cmaxi++ :
				(maxi<cnt) ? maxi=cnt , cmaxi=1 : true;
		}

	cout << maxi << ' ' << cmaxi << endl;

	return 0;
}