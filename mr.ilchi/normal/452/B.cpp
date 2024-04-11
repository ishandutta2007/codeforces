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
 */

#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <complex> 
#include <bitset> 
#include <iomanip> 
#include <utility> 

using namespace std;

bool mark[1010][1010];
bool flag;
int n,m;
pair<int,int> a[10],b[10];

double get (pair<int,int> p[]){
	double ret = 0.0;
	for (int i=0; i<3; i++){
		int dx = p[i].first - p[i+1].first;
		int dy = p[i].second- p[i+1].second;
		ret+= sqrt(dx * dx + dy * dy + 0.0);
	}
	return ret;
}

void go (int pos){
	if (pos == 4){
		if (get(b) > get(a))
			for (int i=0; i<4; i++)
				a[i] = b[i];	
		return;
	}
	int s = (pos%2 == 0) ? (1) : (-1);
	int X,Y;
	if (s == 1)
		X = 0, Y = 0;
	else
		X = n, Y = m;
	for (int dx=0; dx<=4; dx++){
		for (int dy=0; dy<=4; dy++){
			b[pos] = make_pair(X + dx * s, Y + dy * s);
			if (b[pos].first>=0 && b[pos].first<=n && b[pos].second>=0 && b[pos].second<=m && !mark[b[pos].first][b[pos].second]){
				mark[b[pos].first][b[pos].second] = true;
				go(pos+1);
				mark[b[pos].first][b[pos].second] = false;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	if (n < m){
		swap(n,m);
		flag = true;
	}
	for (int i=0; i<4; i++)
		a[i] = make_pair(0,0);
	go(0);
	if (flag)
		for (int i=0; i<4; i++)
			swap(a[i].first, a[i].second);
	for (int i=0; i<4; i++)
		cout << a[i].first << ' ' << a[i].second << endl;
	return 0;
}