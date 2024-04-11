#include <iostream>
#include <vector>
#include <climits>

using namespace std;

template <class T>
class Heap {
public:
	Heap(int size) {
		heapMap = new int[size];
	}
	~Heap() {
		delete[] heapMap;
	}
	//value, index
	void insert(std::pair<T, int> element) {
		heap.push_back(element);
		heapMap[element.second] = heap.size() - 1;
		heapifyup(heap.size() - 1);
	}
	std::pair<T, int> deletemin() {
		std::pair<T, int> min = heap.front();
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		heapifydown(0);
		return min;
	}
	bool decreaseKey(int index, T newVal) {
		if(newVal < heap[heapMap[index]].first) {
			heap[heapMap[index]] = make_pair(newVal, heap[heapMap[index]].second);
			heapifyup(heapMap[index]);
			return true;
		}
		return false;
	}
	int size() { return heap.size(); }
public:
	int *heapMap;
private:
	int left(int parent) {
		unsigned int i = (parent << 1) + 1;
		return i < heap.size() ? i : -1;
	}
	int right(int parent) {
		unsigned int i = (parent << 1) + 2;
		return i < heap.size() ? i : -1;
	}
	int parent(int child) {
		if(child != 0)
			return (child - 1) >> 1;
		return -1;
	}
	void heapifyup(int index) {
		while(index > 0 && parent(index) >= 0 && heap[index] < heap[parent(index)]) {
			heapMap[heap[index].second] = parent(index);
			heapMap[heap[parent(index)].second] = index;
			std::swap(heap[parent(index)], heap[index]);
			index = parent(index);
		}
	}
	void heapifydown(int index) {
		if(heap.size() == 0) return;
		int child = left(index);
		if(child > 0 && right(index) > 0 && heap[right(index)] < heap[child])
			child = right(index);
		if(child > 0 && heap[child] < heap[index]) {
			heapMap[heap[index].second] = child;
			heapMap[heap[child].second] = index;
			std::pair<T, int> temp = heap[index];
			heap[index] = heap[child];
			heap[child] = temp;
			heapifydown(child);
		}
	}
private:
	std::vector<std::pair<T, int> > heap;
};

struct Vertex {
	int index;
	long long a;
	vector<pair<Vertex*, long long> > adj;
};

int n, m, x, y;
long long cost;
long long w;
vector<Vertex*> graph;

long long prim() {
	bool visited[n];
	Heap<long long> pq(n);
	for(int i = 0; i < n; i++) {
		visited[i] = false;
		pq.insert(make_pair(LLONG_MAX, i));
	}
	visited[0] = true;
	long long treeCost = 0;
	for(unsigned int i = 0; i < graph[0]->adj.size(); i++) {
		pq.decreaseKey(graph[0]->adj[i].first->index, graph[0]->adj[i].second);
	}
	pq.decreaseKey(0, 0);
	while(pq.size()) {
		pair<long long, int> p = pq.deletemin();
		if(p.first == LLONG_MAX) {
			return LLONG_MAX;
		}
		treeCost += p.first;
		visited[p.second] = 1;
		for(unsigned int i = 0; i < graph[p.second]->adj.size(); i++) {
			int idx = graph[p.second]->adj[i].first->index;
			if(!visited[idx]) {
				pq.decreaseKey(idx, graph[p.second]->adj[i].second);
			}
		}
	}
	return treeCost;
}

int main() {
	cin >> n >> m;
	long long mincost = 1e12;
	int minidx = 0;
	for(int i = 0; i < n; i++) {
		Vertex *v = new Vertex();
		cin >> v->a;
		v->index = i;
		graph.push_back(v);
		if(v->a < mincost) {
			mincost = v->a;
			minidx = i;
		}
	}
	Vertex *minvert = graph[minidx];
	for(int i = 0; i < n; i++) {
		if(i != minidx) {
			// connect each vertex to minvert
			Vertex *v = graph[i];
			v->adj.push_back(make_pair(minvert, v->a + minvert->a));
			minvert->adj.push_back(make_pair(v, v->a + minvert->a));
		}
	}

	for(int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		x--; y--;
		graph[x]->adj.push_back(make_pair(graph[y], w));
		graph[y]->adj.push_back(make_pair(graph[x], w));
	}

	// find the minimum spanning tree
	cout << prim() << endl;

//	for(int i = 0; i < m; i++) {
//		cin >> x >> y >> w;
//		x--; y--; // 0-indexing
//		Vertex *v1 = graph[x];
//		Vertex *v2 = graph[y];
//		int j = 0;
//		long long dist = 0;
//		// if v1, v2 are already connected, just update to special offer if beneficial
//		for(; j < v1->adj.size(); j++) {
//			if(v1->adj[j].first == v2) {
//				dist = min(v1->adj[j].second, w);
//				v1->adj[j] = make_pair(v2, dist);
//				break;
//			}
//		}
//		if(j != v1->adj.size()) {
//			for(int k = 0; k < v2->adj.size(); k++) {
//				if(v2->adj[k].first == v1) {
//					v2->adj[k] = make_pair(v1, dist);
//				}
//			}
//		}else {
//			// if v1, v2 are not connected, then connect them if we can drop the most
//			// costly edge connected to either v1 or v2
//			int idx1 = -1;
//			long long maxval1 = w;
//			for(int k = 0; k < v1->adj.size(); k++) {
//				if(v1->adj[k].second > maxval1) {
//					idx1 = k;
//					maxval1 = v1->adj[k].second;
//				}
//			}
//			int idx2 = -1;
//			long long maxval2 = w;
//			for(int k = 0; k < v2->adj.size(); k++) {
//				if(v2->adj[k].second > maxval2) {
//					idx2 = k;
//					maxval2 = v2->adj[k].second;
//				}
//			}
//
//		}
//	}
}