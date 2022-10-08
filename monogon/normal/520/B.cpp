#include <bits/stdc++.h>

#define in std::cin
#define out std::cout
#define endl std::endl
#define MAX(a, b) std::max(a, b)
#define MAX3(a, b, c) std::max(a, std::max(b, c))
#define MIN(a, b) (a < b ? a : b)
#define MIN3(a, b, c) std::min(a, std::min(b, c))
#define MAXE(a, b) a = std::max(a, b)
#define MINE(a, b) a = std::min(a, b)
#define GETBIT(a, n) ((a >> n) & 1)
#define BITCOUNT(a) __builtin_popcount(a)
#define S std::string
#define Ss std::stringstream
#define PQI std::priority_queue<int>
#define PQS std::priority_queue<std::string>
#define PQPII std::priority_queue<std::pair<int, int> >
#define PQPIS std::priority_queue<std::pair<int, std::string> >
#define PQPSI std::priority_queue<std::pair<std::string, int> >
#define PQPSS std::priority_queue<std::pair<std::string, std::string> >
#define VI std::vector<int>
#define VS std::vector<std::string>
#define VPII std::vector<std::pair<int, int> >
#define VPSI std::vector<std::pair<std::string, int> >
#define VPIS std::vector<std::pair<int, std:;string> >
#define VPSS std::vector<std::pair<std::string, std::string> >
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


class Heap {
public:
	Heap();
	~Heap();
	void insert(PII element);
	PII deletemin();
	void decreaseKey(int index, PII newVal);
	int size() { return heap.size(); }
public:
	int heapMap[10001];
private:
	int left(int parent);
	int right(int parent);
	int parent(int child);
	void heapifyup(int index);
	void heapifydown(int index);
private:
	VPII heap;
};

Heap::Heap() {}
Heap::~Heap() {}
void Heap::insert(PII element) {
	heap.push_back(element);
	heapMap[element.second] = heap.size() - 1;
	heapifyup(heap.size() - 1);
}
PII Heap::deletemin() {
	PII min = heap.front();
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	heapifydown(0);
	return min;
}
void Heap::decreaseKey(int index, PII newVal) {
	heap[heapMap[index]] = MP(MIN(heap[heapMap[index]].first, newVal.first), heap[heapMap[index]].second);
	heapifyup(heapMap[index]);
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

int n, m;
bool visited[10001];
Heap heap;

int main() {
	in >> n >> m;
	for(int i = 0; i < 10001; i++)
		heap.insert(MP(1e9, i));
	heap.decreaseKey(n, MP(0, n));
	while(heap.size() > 0) {
		PII i = heap.deletemin();
		if(i.second == m) {
			out << i.first;
			break;
		}
		visited[i.second] = 1;
		if(!visited[2 * i.second] && 2 * i.second < 10001)
			heap.decreaseKey(2 * i.second, MP(i.first + 1, 2 * i.second));
		if(i.second > 0 && !visited[i.second - 1])
			heap.decreaseKey(i.second - 1, MP(i.first + 1, i.second - 1));
	}
}