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
#include <set>

using namespace std;

const int maxN= 1000+5;

bool mark[maxN];
int n,k;
int deg[maxN];

struct node{
	int v;

	node (int _v=-1) : v(_v) {}

	inline bool operator < (const node &sec) const{
		return v<sec.v;
	}
};
set <node> sit;
/*****************************/
int main(){
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> deg[i];
		if (deg[i]==0)
			sit.insert (node(i));
	}

	while (sit.size()){
		node top= *sit.begin();
		sit.erase (top);
		cout << top.v << ' ';
		mark[top.v]= true;
		for (int i=top.v-k;i>0;i--){
			if (!mark[i]){
				deg[i]--;
				if (deg[i]==0)
					sit.insert (node(i));
			}
		}
	}
	
	cout << endl;

	return 0;
}