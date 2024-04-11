#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


#define MAX (1+(1<<6)) // Why? :D
#define inf 0x7fffffff

int arr[110000];
int tree[510000];
int lazy[510000];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] += value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -inf; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result
	
	return res;
}


int val[110000];

int main() {




	memset(lazy, 0, sizeof lazy);

	int m;
	cin >> m;
	int p[m];
	int t[m];
	int x[m];
	for(int i = 1; i <= m; i++) arr[i] = 0;
	for(int i = 0; i < m; i++){
		cin >> p[i] >> t[i];
		if(t[i]) cin >> x[i];
	}

	build_tree(1, 1, m);
	for(int i = 0; i < m; i++){
		if(t[i]){
			val[p[i]] = x[i];
			update_tree(1, 1, m, 1, p[i], 1);
		} else {
			update_tree(1, 1, m, 1, p[i], -1);
		}
		int s = 0;
		int e = m+1;
		while(s + 1 < e){
			int d = (s+e)/2;
			if(query_tree(1,1,m,d,m) > 0){
				s = d;
			} else {
				e = d;
			}
		}
		if(s == 0){
			cout << -1 << endl;
		} else {
			cout << val[s] << endl;
		}
	}
}