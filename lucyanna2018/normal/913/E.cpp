/*#### bits/stdc++.h */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<deque>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
/*####*/

string a[256][3];//F, T, E
string res[256];
#define F 0
#define T 1
#define E 2
bool vis[256][3];

bool cmp(const string&x,const string&y){
	if(x.length() != y.length())return x.length() < y.length();
	return x<y;
}
void upd(string&x,const string&y){
	if(x == "" || cmp(y, x))
		x = y;
}
int main(){
	a[(1<<4) + (1<<5) + (1<<6) + (1<<7)][0] = "x";
	a[(1<<2) + (1<<3) + (1<<6) + (1<<7)][0] = "y";
	a[(1<<1) + (1<<3) + (1<<5) + (1<<7)][0] = "z";
	int n = 256;
	for(int i=0; i<n*3; i++){
		int x = -1, y = -1;
		for(int p=0; p<n; p++)
		for(int j=0; j<3; j++)
			if(!vis[p][j] && a[p][j] != "" && (x == -1 || cmp(a[p][j], a[x][y]))){
				x = p;
				y = j;
			}
		vis[x][y] = true;

		if(y == F){//F
			upd(a[x][T], a[x][F]); //T::=F
			upd(a[n-1-x][F], "!" + a[x][F]);// F::= '!' F
			for(int p=0; p<n; p++)if(vis[p][T]){//T::=T '&' F
				upd(a[p & x][T], a[p][T] + "&" + a[x][F]);
			}
		}
		if(y == T){//T
			upd(a[x][E], a[x][T]); //E::=T
			for(int p=0; p<n; p++)if(vis[p][E]){//E::= E '|' T
				upd(a[p | x][E], a[p][E] + "|" + a[x][T]);
			}
			for(int p=0; p<n; p++)if(vis[p][F]){//T::= T '&' F
				upd(a[x & p][T], a[x][T] + "&" + a[p][F]);
			}
		}
		if(y == E){//E
			upd(a[x][F], "("+a[x][E]+")"); // F::= '(' + E + ')';
			for(int p=0; p<n; p++)if(vis[p][T]){//E::= E '|' T
				upd(a[x | p][E], a[x][E] + "|" + a[p][T]);
			}
		}
	}
	int _;char s[99];
	for(int i=0; i<256; i++){
		res[i] = "";
		upd(res[i], a[i][0]);
		upd(res[i], a[i][1]);
		upd(res[i], a[i][2]);
//		puts(res[i].c_str());
	}
	for(scanf("%d",&_); _--;){
		scanf("%s",s);
		int ret = 0;
		for(int i=0; i<8; i++)if(s[i] == '1')
			ret += (1<<i);
		printf("%s\n",res[ret].c_str());
	}
	return 0;
}