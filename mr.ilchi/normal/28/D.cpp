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
#include <map>
#include <algorithm>

#define Pair pair<int,int>

using namespace std;

const int maxN= 100000+5;

int n;
int v[maxN], z[maxN], f[maxN], b[maxN], next[maxN];
map <Pair, Pair> dp;

inline void print (int v, int cnt){
	if (v==-1){
		printf ("%d\n", cnt);
		return;
	}
	print (next[v], cnt+1);
	printf("%d ", v);
}
/*********************************/
int main(){
	scanf ("%d", &n);
	for (int i=1;i<=n;i++){
		scanf ("%d%d%d%d", &v[i], &z[i], &f[i], &b[i]);
	}
	
	for (int i=1;i<=n;i++){
		if (f[i]==0){
			map <Pair,Pair> :: iterator it= dp.find(make_pair(z[i],b[i]));
			if (it==dp.end()){
				dp [make_pair(z[i],b[i])]= make_pair(v[i],i);
				next[i]= -1;
			}
			else{
				if ((it->second).first<v[i]){
					dp [make_pair(z[i],b[i])]= Pair(v[i],i);
					next[i]= -1;
				}
			}
		}

		else{
			map <Pair,Pair> :: iterator it= dp.find(make_pair(f[i],b[i]+z[i]));
			if (it!=dp.end()){
				int cur= (it->second).first + v[i];
				if (dp [make_pair(f[i]+z[i],b[i])].first < cur){
					dp [make_pair(f[i]+z[i],b[i])]= make_pair(cur,i);
					next[i]= (it->second).second;
				}
			}
		}
	}

	int res=0,End=0;

	for (map <Pair,Pair> :: iterator it= dp.begin(); it!=dp.end(); it++){
		if (((it->first).second)==0 && res<(it->second).first){
			res= (it->second).first; End= (it->second).second;
		}			
	}

	if (res==0){
		printf ("0\n");
		return 0;
	}

	print (End,0); printf ("\n");

	return 0;
}