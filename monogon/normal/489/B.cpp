#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define in std::cin
#define out std::cout
#define endl std::endl
#define MAX(a, b) std::max(a, b)
#define MAX3(a, b, c) std::max(a, std::max(b, c))
#define MIN(a, b) std::min(a, b)
#define MIN3(a, b, c) std::min(a, std::min(b, c))
#define MAXE(a, b) a = std::max(a, b)
#define MINE(a, b) a = std::min(a, b)
#define GETBIT(a, n) ((a >> n) & 1)
#define BITCOUNT(a) __builtin_popcount(a)
#define S std::string
#define Ss std::stringstream
#define VI std::vector<int>
#define VS std::vector<std::string>
#define VVI std::vector<std::vector<int> >
#define MP(a, b) std::make_pair(a, b)
#define PII std::pair<int, int>
#define PSI std::pair<std::string, int>
#define PIS std::pair<int, std::string>
#define PSS std::pair<std::string, std::string>
#define SI std::set<int>
#define SS std::set<std::string>
#define SPII std::set<std::pair<int, int> >
#define SPSI std::set<std::pair<std::string, int> >
#define SPIS std::set<std::pair<int, std::string> >
#define SPSS std::set<std::pair<std::string, std::string> >
#define MSI std::multiset<int>
#define MSS std::multiset<std::string>
#define VII std::vector<int>::iterator
#define VSI std::vector<std::string>::iterator
#define VVII std::vector<std::vector<int> >::iterator
#define SII std::set<int>::iterator
#define SPIII std::set<std::pair<int, int> >::iterator
#define SPSII std::set<std::pair<std::string, int> >::iterator
#define SPISI std::set<std::pair<int, std::string> >::iterator
#define SPSSI std::set<std::pair<std::string, std::string> >::iterator
#define MSIII std::multiset<int>::iterator
#define MSSI std::multiset<std::string>::iterator
#define MAPII std::map<int, int>
#define MAPSS std::map<std::string, std::string>
#define MAPIS std::map<int, std::string>
#define MAPSI std::map<std::string, int>

VVI mat;

int networkFlow(int source, int sink) {
	if(source == sink)
		return INT_MAX;
	std::vector<std::vector<int> > mat2(mat);
	int totalFlow = 0;
	int prevNode[mat2.size()];
	int flow[mat2.size()];
	bool visited[mat2.size()];
	while(true) {
		//find path with highest capacity
		//uses a modified dijkstra's algorithm
		for(unsigned int i = 0; i < mat2.size(); i++) {
			prevNode[i] = -1;
			flow[i] = 0;
			visited[i] = false;
		}
		flow[source] = INT_MAX;
		int maxFlow = 0;
		int maxLoc = -1;
		while(true) {
			maxFlow = 0;
			maxLoc = -1;
			//find unvisited node with
			//highest capacity to it
			for(unsigned int i = 0; i < mat2.size(); i++) {
				if(flow[i] > maxFlow && !visited[i]) {
					maxFlow = flow[i];
					maxLoc = i;
				}
			}
			if(maxLoc == -1 || maxLoc == sink)
				break;
			visited[maxLoc] = true;
			//update its neighbors
			for(unsigned int i = 0; i < mat2.size(); i++) {
				if(i != maxLoc && mat2[maxLoc][i] > 0 && flow[i] < std::min(maxFlow, mat2[maxLoc][i])) {
					prevNode[i] = maxLoc;
					flow[i] = std::min(maxFlow, mat2[maxLoc][i]);
				}
			}
		}
		if(maxLoc == -1)
			return totalFlow;
		int pathCapacity = flow[sink];
		totalFlow += pathCapacity;
		//add that flow to the network,
		//update capacity appropriately
		int curNode = sink;
		//for each arc, prevNode[curNode]
		//curNode on path
		while(curNode != source) {
			int nextNode = prevNode[curNode];
			mat2[nextNode][curNode] -= pathCapacity;
			mat2[curNode][nextNode] += pathCapacity;
			curNode = nextNode;
		}
	}
	return totalFlow;
}

int n, m;
int b[100], g[100];

int main() {
	in >> n;
	for(int i = 0; i < n; i++) {
		in >> b[i];
	}
	in >> m;
	for(int i = 0; i < m; i++) {
		in >> g[i];
	}
	//0 : n-1 = boy
	//n : n + m - 1 = girl
	//n + m = source
	//n + m + 1 = sink
	mat = std::vector<std::vector<int> >(n + m + 2, std::vector<int>(n + m + 2, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			mat[i][n + j] = abs(b[i] - g[j]) <= 1;
	for(int i = 0; i < n; i++)
		mat[n + m][i] = 1;
	for(int j = 0; j < m; j++)
		mat[n + j][n + m + 1] = 1;
	out << networkFlow(n + m, n + m + 1) << endl;
}