#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
using namespace std;
int DEBUG = 0;
int INFTY = 48802427;
int min(int a, int b) {
  return (a < b ? a : b);
}
void print_vec(int *vec, int n, const char *str=NULL) {
  if(str != NULL) printf("%s ", str);
  for(int i=0; i<n; i++) {
    if(i>0) printf(" ");
    printf("%d", vec[i]);
  }
  printf("\n");
  fflush(stdout);
}
int **alloc2d(int M, int N) {
  int **a = new int * [M];
  for(int i=0; i<M; i++) a[i] = new int [N];
  return a;
}
void swap(int &a, int &b) {
  int tmp = b; b = a; a = tmp;
}
void upheap(int i, int *heap, int *n2h, int nheap, int *dist){
  while(i>0) {
    int parent = int((i-1)/2);
    if(dist[heap[i]] < dist[heap[parent]]) {
      swap(heap[i], heap[parent]);
      n2h[heap[i]] = i;
      n2h[heap[parent]] = parent;
      i = parent;
    } else {
      return;
    }
  }
}
void downheap(int i, int *heap, int *n2h, int nheap, int *dist){
  int left = i*2+1;
  int right = i*2+2;
  while(left < nheap) {
    int child = left;
    if(right < nheap && dist[heap[left]] > dist[heap[right]]) {
      child = right;
    }
    if(dist[heap[i]] > dist[heap[child]]) {
      swap(heap[i], heap[child]);
      n2h[heap[i]] = i;
      n2h[heap[child]] = child;
      i = child;
      left = i*2+1;
      right = i*2+2;
    } else {
      return;
    }
  }
}
int updateheap(int i, int *heap, int *n2h, int nheap, int *dist){
  //i = heapindex
  if(i != 0 && dist[heap[i]] < dist[heap[int((i-1)/2)]]){
    int tmp = heap[i];
    heap[i] = heap[int((i-1)/2)];
    heap[int((i-1)/2)] = tmp;
    n2h[heap[i]] = i;
    n2h[heap[int((i-1)/2)]] = int((i-1)/2);
    upheap(int((i-1)/2), heap, n2h, nheap, dist);
  }
  if(2*i + 1 < nheap && dist[heap[i]] > dist[heap[2*i+1]]){
    int tmp = heap[i];
    heap[i] = heap[2*i+1];
    heap[2*i+1] = tmp;
    n2h[heap[i]] = i;
    n2h[heap[2*i+1]] = 2*i+1;
    downheap(2*i+1, heap, n2h, nheap, dist);
  }
  if(2*i + 2 < nheap && dist[heap[i]] > dist[heap[2*i+2]]){
    int tmp = heap[i];
    heap[i] = heap[2*i+2];
    heap[2*i+2] = tmp;
    n2h[heap[i]] = i;
    n2h[heap[2*i+2]] = 2*i+2;
    downheap(2*i+2, heap, n2h, nheap, dist);
  }
}

struct NODE{
  int wgt;
  int loc;
  NODE(int wgt0, int loc0) : wgt(wgt0), loc(loc0) {}
};

main(int argc, char **argv) {
  DEBUG = (argc>=3) ? atoi(argv[2]) : 0;
  int n, m, src;
  scanf("%d%d%d", &n, &m, &src);
  src--;
  //int **adj = alloc2d(n, n);
  //for(int i = 0; i < n; i++){
  //  for(int j = 0; j < n; j++){
  //    adj[i][j] = INFTY;
  //  }
  //  adj[i][i] = 0;
  //}
  vector<NODE> nodes[n];
  for(int i = 0; i < m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    //adj[a-1][b-1] = adj[b-1][a-1] = min(adj[a-1][b-1], c);
    bool found = false;
    for(int i=0; i<nodes[a-1].size(); i++) {
      if(nodes[a-1][i].loc == b-1) {
	nodes[a-1][i].wgt = min(c, nodes[a-1][i].wgt); 
	found = true; break;
      } 
    }
    if(found){
      for(int i=0; i<nodes[b-1].size(); i++) {
	if(nodes[b-1][i].loc == a-1) {
	  nodes[b-1][i].wgt = min(c, nodes[b-1][i].wgt); 
	  found = true; break;
	} 
      }
    }
    if(!found) {
      nodes[a-1].push_back(NODE(c, b-1)); 
      nodes[b-1].push_back(NODE(c, a-1));
    }
  }
  int nsilo = 0;
  int silo;
  scanf("%d", &silo);
  //printf("%d\n\n", silo);
  int heap[n];
  int n2h[n];
  int nheap = 0;
  int dist[n];
  int visited[n];
  int nvisited = 0;
  for(int j = 0; j < n; j++){
    dist[j] = INFTY;
    visited[j] = 0;
    n2h[j] = -1;
  }
  dist[src] = 0;
  heap[nheap] = src;
  n2h[src] = nheap;
  nheap++;
  while(nvisited != n) {
    int minv = heap[0]; 
    if(DEBUG) {
      printf("minv= %d, nheap= %d, nvisited= %d\n",
	     minv, nheap, nvisited);
      print_vec(heap, nheap, "heap");
    }
    visited[minv] = 1;
    nvisited++;
    for(int j = 0; j < nodes[minv].size(); j++){
      int outv = nodes[minv][j].loc;
      if(dist[minv] + nodes[minv][j].wgt < dist[outv]){
	dist[outv] = dist[minv] + nodes[minv][j].wgt;
	// printf("dist[%d] = %d\n", j, dist[j]);
	if(n2h[outv] == -1){
	  heap[nheap] = outv;
	  n2h[outv] = nheap;
	  nheap ++;
	  // print_vec(heap, nheap, "after add heap   ");
	}
	updateheap(n2h[outv], heap, n2h, nheap, dist); 
	//print_vec(heap, nheap, "after update heap");
      }
    }
    //print_vec(heap, nheap, "heap before remove");
    heap[0] = heap[--nheap];
    downheap(0, heap, n2h, nheap, dist);
  }
  //print_vec(dist, n, "DISTANCE: ");
  for(int i = 0; i < n; i++){
    if(dist[i] == silo){
      nsilo++;
      nsilo++;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < nodes[i].size(); j++){
      int k = nodes[i][j].loc;
      //printf("%d %d\n", i, k);
      if(dist[i] > silo && dist[k] < silo){
	nsilo ++;
	//printf("1\n");
      } else if(dist[i] < silo && dist[k] > silo){
	nsilo ++;
	//printf("1\n");
      } else if(dist[i] < silo && dist[k] < silo){
	//printf("dist[i] %d dist[k] %d wgt = %d\n", dist[i], dist[k], nodes[i][j].wgt);
	if((dist[i] + dist[k] + nodes[i][j].wgt) == (silo + silo)){
	  nsilo++;
	  //printf("1\n");
	} else if((dist[i] + dist[k] + nodes[i][j].wgt) > (silo + silo)){
	  nsilo++;
	  nsilo++;
	  //printf("2\n");
	}
      } else if(dist[i] == silo && dist[k] < silo){
	if((dist[k] + nodes[i][j].wgt) > silo){
	  nsilo++;
	  //printf("1\n");
	}
      } else if(dist[i] < silo && dist[k] == silo){
	if((dist[i] + nodes[i][j].wgt) > silo){
	  nsilo++;
	  //printf("1\n");
	}
      }
    }
  }
  printf("%d\n", nsilo/2);
  exit(0);
}