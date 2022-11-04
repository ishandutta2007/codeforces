/*
 * in the name of god
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
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN = 100 * 1000 + 10;

bool mark[maxN];
int n,m;
ll prof;
vector <int> adj[maxN];
vector <pii> ans;

struct node{
	int size,cost,ind;
	node () {}
	node (int size, int cost, int ind) : size(size) , cost(cost) , ind(ind) {}
	bool operator < (const node &A) const{
		return (size!=A.size) ? (size<A.size) : (cost>A.cost);
	}
}a[maxN],b[maxN];

bool fit (int x, int y){
	return (x<=n) && (y<=m) && (a[x].cost>=b[y].cost) && (a[x].size<=b[y].size) && (b[y].size-a[x].size<=1);
}

void check (vector <node> &person, vector <node> &shoe){

	if (person.empty())
		return;

	if (person.size() == shoe.size()){
		int len = (int)shoe.size();
		if (person.back().cost<shoe.back().cost)
			swap(shoe[len-1],shoe[len-2]);
		for (int i=0;i<(int)person.size();i++){
			prof+=shoe[i].cost;
			ans.push_back(pii(person[i].ind,shoe[i].ind));
			mark[shoe[i].ind] = true;
		}
	}
	else if ((int)person.size() == (int)shoe.size()-1){
		int minPos=0;
		for (int i=1; i<(int)shoe.size(); i++) if (shoe[i].cost<shoe[minPos].cost) minPos=i;
		shoe.erase(shoe.begin()+minPos);
		for (int i=0;i<(int)person.size(); i++){
			prof+=shoe[i].cost;
			ans.push_back(pii(person[i].ind,shoe[i].ind));
			mark[shoe[i].ind] = true;
		}
	}
	else{
		while (true){
			cout << ":D" << endl;
		}
	}
	person.clear(); shoe.clear();
}

int main(){

	ios_base::sync_with_stdio(false);

	cin >> m; for (int i=1; i<=m; i++) { cin >> b[i].cost >> b[i].size; b[i].ind = i; }
	cin >> n; for (int i=1; i<=n; i++) { cin >> a[i].cost >> a[i].size; a[i].ind = i; }

	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	
	int poi = 1;

	for (int i=1; i<=n; i++){
		while (poi<=m && b[poi].size<a[i].size) poi++;
		if (fit(i,poi)) adj[i].push_back(poi);
		if (fit(i,poi+1)) adj[i].push_back(poi+1);
	}

	vector <node> person,shoe;

	for (int i=1; i<=n; i++){
		
		if (person.size() == shoe.size())
			check(person,shoe);

		for (int j=0; j<(int)adj[i].size(); j++) if (mark[b[adj[i][j]].ind]){
			adj[i].erase(adj[i].begin()+j); j--;
		}

		if (adj[i].empty())
			continue;

		if (!shoe.empty() && b[adj[i][0]].size>shoe.back().size){
			check(person,shoe);
			for (int j=0;j<(int)adj[i].size(); j++)
				shoe.push_back(b[adj[i][j]]);
			person.push_back(a[i]);
		}
		else{
			for (int j=0;j<(int)adj[i].size(); j++) if ((shoe.empty()) || (b[adj[i][j]].size > shoe.back().size)) 
				shoe.push_back(b[adj[i][j]]);
			person.push_back(a[i]);
		}
	}

	check(person,shoe);

	cout << prof << endl;
	cout << ans.size() << endl;
	for (int i=0; i<(int)ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;

	return 0;
}