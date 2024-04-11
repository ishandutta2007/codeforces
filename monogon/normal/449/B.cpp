#include <bits/stdc++.h>

#define in std::cin
#define out std::cout
#define endl std::endl
#define Max(a, b) ((b) > (a) ? (b) : (a))
#define Max3(a, b, c) Max(a, Max(b, c))
#define Min(a, b) ((b) < (a) ? (b) : (a))
#define Min3(a, b, c) Min(a, Min(b, c))
#define MaxE(a, b) a = Max(a, b)
#define MinE(a, b) a = Min(a, b)
#define Getbit(a, n) ((a >> n) & 1)
#define Bitcount(a) __builtin_popcount(a)
#define S std::string
#define Ss std::stringstream
#define VI std::vector<int>
#define VS std::vector<std::string>
#define VPII std::vector<std::pair<int, int> >
#define VPSI std::vector<std::pair<std::string, int> >
#define VPIS std::vector<std::pair<int, std:;string> >
#define VPSS std::vector<std::pair<std::string, std::string> >
#define Mp(a, b) std::make_pair(a, b)
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
#define VII std::vector<int>::iterator
#define VSI std::vector<std::string>::iterator
#define VPIII std::vector<std::pair<int, int> >::iterator
#define VPISI std::vector<std::pair<int, std::string> >::iterator
#define VPSII std::vector<std::pair<std::string, int> >::iterator
#define VPSSI std::vector<std::pair<std::string, std::string> >::iterator
#define MsI std::multiset<int>
#define MsS std::multiset<std::string>
#define MsPII std::multiset<std::pair<int, int> >
#define MsPSI std::multiset<std::pair<std::string, int> >
#define MsPIS std::multiset<std::pair<int, std::string> >
#define MsPSS std::multiset<std::pair<std::string, std::string> >
#define SII std::set<int>::iterator
#define SPIII std::set<std::pair<int, int> >::iterator
#define SPSII std::set<std::pair<std::string, int> >::iterator
#define SPISI std::set<std::pair<int, std::string> >::iterator
#define SPSSI std::set<std::pair<std::string, std::string> >::iterator
#define MsII std::multiset<int>::iterator
#define MsSI std::multiset<std::string>::iterator
#define MsPIII std::multiset<std::pair<int, int> >::iterator
#define MsPSII std::multiset<std::pair<std::string, int> >::iterator
#define MsPISI std::multiset<std::pair<int, std::string> >::iterator
#define MsPSSI std::multiset<std::pair<std::string, std::string> >::iterator
#define MapII std::map<int, int>
#define MapSS std::map<std::string, std::string>
#define MapIS std::map<int, std::string>
#define MapSI std::map<std::string, int>
#define MapIII std::map<int, int>::iterator
#define MapSSI std::map<std::string, std::string>::iterator
#define MapISI std::map<int, std::string>::iterator
#define MapSII std::map<std::string, int>::iterator
#define INF 922337203685477

class Heap {
public:
	Heap(int size);
	~Heap();
	void insert(std::pair<long long, int> element);
	std::pair<long long, int> deletemin();
	bool decreaseKey(int index, long long newVal);
	int size() { return heap.size(); }
public:
	int *heapMap;
private:
	int left(int parent);
	int right(int parent);
	int parent(int child);
	void heapifyup(int index);
	void heapifydown(int index);
private:
	std::vector<std::pair<long long, int> > heap;
};

Heap::Heap(int size) {
	heapMap = new int[size];
}
Heap::~Heap() {
	delete[] heapMap;
}
void Heap::insert(std::pair<long long, int> element) {
	heap.push_back(element);
	heapMap[element.second] = heap.size() - 1;
	heapifyup(heap.size() - 1);
}
std::pair<long long, int> Heap::deletemin() {
	PII min = heap.front();
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	heapifydown(0);
	return min;
}
bool Heap::decreaseKey(int index, long long newVal) {
	if(newVal <= heap[heapMap[index]].first) {
		heap[heapMap[index]] = Mp(newVal, heap[heapMap[index]].second);
		heapifyup(heapMap[index]);
		return true;
	}
	return false;
}
void Heap::heapifyup(int index) {
	while(index > 0 && parent(index) >= 0 && heap[index] < heap[parent(index)]) {
		heapMap[heap[index].second] = parent(index);
		heapMap[heap[parent(index)].second] = index;
		std::swap(heap[parent(index)], heap[index]);
		index = parent(index);
	}
}
void Heap::heapifydown(int index) {
	if(heap.size() == 0) return;
	int child = left(index);
	if(child > 0 && right(index) > 0 && heap[right(index)] < heap[child])
		child = right(index);
	if(child > 0 && heap[child] < heap[index]) {
		heapMap[heap[index].second] = child;
		heapMap[heap[child].second] = index;
		PII temp = heap[index];
		heap[index] = heap[child];
		heap[child] = temp;
		heapifydown(child);
	}
}
int Heap::left(int parent) {
	int i = (parent << 1) + 1;
	return i < heap.size() ? i : -1;
}
int Heap::right(int parent) {
	int i = (parent << 1) + 2;
	return i < heap.size() ? i : -1;
}
int Heap::parent(int child) {
	if(child != 0)
		return (child - 1) >> 1;
	return -1;
}

int n, m, k, x, y, w, count;
VPII roads[100000];
long long tracks[100000];
bool visited[100000], improved[100000];
int parent[100000];
long long dist[100000];

void dijkstra(int a) {
	Heap pq(n);
	for(int i = 0; i < n; i++) {
		visited[i] = 0;
		parent[i] = -1;
		pq.insert(Mp(tracks[i], i));
	}
	pq.decreaseKey(a, 0);
	while(pq.size()) {
		std::pair<long long, int> p = pq.deletemin();
		visited[p.second] = 1;
		dist[p.second] = p.first;
		if(p.first == INF)
			break;
		//for each neightbor q
		for(unsigned int i = 0; i < roads[p.second].size(); i++) {
			if(!visited[roads[p.second][i].first] && pq.decreaseKey(roads[p.second][i].first, p.first + roads[p.second][i].second)) {
				parent[roads[p.second][i].first] = p.second;
				if(!improved[roads[p.second][i].first] && tracks[roads[p.second][i].first] < INF) {
					improved[roads[p.second][i].first] = 1;
					count++;
				}
			}
		}
	}
	while(pq.size()) {
		std::pair<long long, int> p = pq.deletemin();
		visited[p.second] = 1;
		dist[p.second] = INF;
	}
}

int main() {
	in >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		in >> x >> y >> w;
		roads[x - 1].push_back(Mp(y - 1, w));
		roads[y - 1].push_back(Mp(x - 1, w));
	}
	for(int i = 0; i < n; i++) {
		tracks[i] = INF;
	}
	for(int i = 0; i < k; i++) {
		in >> x >> w;
		count += (tracks[x - 1] < INF);
		MinE(tracks[x - 1], w);
	}
	dijkstra(0);
	out << count;
}