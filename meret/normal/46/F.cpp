#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <cstring>
#include <sstream>
#include <utility>
using namespace std;

#define X first
#define Y second
#define FI first
#define SE second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef double D;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int cond = 1;
#define db(x) {if(cond){cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define dbv(x) {if(cond){cerr << __LINE__ << " " << #x << ": "; FORE(__i,x) cerr << *__i << " "; cerr << endl;} }

const int N = 1005;

int gp(int* p, int x) {
	if (p[x] != x)
		p[x] = gp(p, p[x]);
	return p[x];
}

void un(int* p, set<int>* keys, set<int>* rooms, int a, int b) {
	a = gp(p, a);
	b = gp(p, b);
	if (a != b) {
		if (keys[a].size() + rooms[a].size() < keys[b].size() + rooms[b].size())
			swap(a, b);
		p[b] = a;
		FORE (it, keys[b])
			keys[a].insert(*it);
		FORE (it, rooms[b])
			rooms[a].insert(*it);
		keys[b].clear();
		rooms[b].clear();
	}
}

int key[N][2];

int nKeys, nRooms, nResidents;

char buf[20];

map<string, int> name;

vector<pair<set<int>, set<int> > > go() {
	int* p = new int[N];
	set<int>* keys = new set<int>[N];
	set<int>* rooms = new set<int>[N];
	for (int i = 1; i <= nRooms; ++i) {
		rooms[i].insert(i);
		p[i] = i;
	}
	for (int i = 1; i <= nResidents; ++i) {
		int pos, gotKeys;
		scanf("%s %d %d", buf, &pos, &gotKeys);
		int cnt = name.size();
		if (name.find(buf) == name.end())
			name[buf] = ++cnt;
		rooms[pos].insert(nRooms + name[buf]);
		for (int j = 0; j < gotKeys; ++j) {
			int a;
			scanf("%d", &a);
			keys[pos].insert(a);
		}
	}
	while (true) {
		bool got = false;
		for (int i = 1; i <= nKeys; ++i) {
			int a = gp(p, key[i][0]);
			int b = gp(p, key[i][1]);
			if (a != b && (keys[a].find(i) != keys[a].end() || keys[b].find(i) != keys[b].end())) {
				un(p, keys, rooms, a, b);
				got = true;
			}
		}
		if (!got)
			break;
	}
	vector<pair<set<int>, set<int> > > result;
	for (int i = 1; i <= nRooms; ++i)
		if (p[i] == i)
			result.PB(MP(keys[i], rooms[i]));
	sort(ALL(result));
	delete[] p;
	delete[] keys;
	delete[] rooms;
	return result;
}

set<int> keys[2][N];
set<int> rooms[2][N];

int p[2][N];

int main()
{
	scanf("%d %d %d", &nRooms, &nKeys, &nResidents);

	for (int i = 1; i <= nKeys; ++i)
		scanf("%d %d", &key[i][0], &key[i][1]);

	if (go() == go())
		printf("YES\n");
	else
		printf("NO\n");



    return 0;
}