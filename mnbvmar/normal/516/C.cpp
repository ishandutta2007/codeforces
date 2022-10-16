#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 100005,
          MaxM = 100005,
          Base = (1<<18),
          PSize = (1<<19);
const LL  Infty = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;

struct PNode {
	int max1start, max2start;
	int max1end,   max2end;
};



int heights[MaxN*2];
int dists[MaxN*2];
LL distStart[MaxN*2], distEnd[MaxN*2];
LL valueStart[MaxN*2], valueEnd[MaxN*2];
int N, M;

PNode join_nodes(const PNode& lhs, const PNode& rhs){
	PNode result;

	// start
	if(valueStart[lhs.max1start] > valueStart[rhs.max1start]){
		result.max1start = lhs.max1start;

		if(valueStart[lhs.max2start] > valueStart[rhs.max1start])
			result.max2start = lhs.max2start;
		else
			result.max2start = rhs.max1start;
		
	} else {
		result.max1start = rhs.max1start;

		if(valueStart[lhs.max1start] > valueStart[rhs.max2start])
			result.max2start = lhs.max1start;
		else
			result.max2start = rhs.max2start;
	}

	// end
	if(valueEnd[lhs.max1end] > valueEnd[rhs.max1end]){
		result.max1end = lhs.max1end;

		if(valueEnd[lhs.max2end] > valueEnd[rhs.max1end])
			result.max2end = lhs.max2end;
		else
			result.max2end = rhs.max1end;
		
	} else {
		result.max1end = rhs.max1end;

		if(valueEnd[lhs.max1end] > valueEnd[rhs.max2end])
			result.max2end = lhs.max1end;
		else
			result.max2end = rhs.max2end;
	}

	return result;
}


PNode tree[PSize];

void make_tree(){
	int L = Base, R = 2*N+Base-1;

	for(int i = 0; i < 2*N; i++)
		tree[Base+i] = PNode{i,2*N,i,2*N};
	for(int i = 2*N; i < Base; i++)
		tree[Base+i] = PNode{2*N,2*N,2*N,2*N};

	L /= 2; R /= 2;
	while(L){
		for(int i = L; i <= R; i++)
			tree[i] = join_nodes(tree[i*2], tree[i*2+1]);
		L /= 2; R /= 2;
	}
}

PNode get_result(int L, int R){
//	printf("get result(%d, %d)\n", L, R);
	L += Base; R += Base;
	PNode result = tree[L];
	if(L != R) result = join_nodes(result, tree[R]);

	while(L/2 != R/2){
		if(L % 2 == 0) result = join_nodes(result, tree[L+1]);
		if(R % 2 == 1) result = join_nodes(result, tree[R-1]);
		L /= 2; R /= 2;
	}
	return result;
}


void input(){
	scanf("%d%d", &N, &M);

	for(int i = 0; i < N; i++) scanf("%d", &dists[i]);
	for(int i = 0; i < N; i++) scanf("%d", &heights[i]);
}


LL get_res(int from, int to){
	if(from >= to) return 0;

	LL total = 0;
	total += 2*heights[from];
	total += 2*heights[to];
	total += distStart[to] - distStart[from];

	return total;
}

int main(){
	input();
	for(int i = 0; i < N; i++){
		dists[N+i] = dists[i];
		heights[N+i] = heights[i];
	}

	distStart[0] = 0;
	for(int i = 0; i < 2*N; i++){
		if(i){
			distStart[i] = distStart[i-1] + dists[i-1];
		}
		valueStart[i] = 2*heights[i] - distStart[i];
	}
	valueStart[2*N] = -Infty;

	distEnd[2*N-1] = 0;
	for(int i = 2*N-1; i >= 0; i--){
		if(i != 2*N-1){
			distEnd[i] = distEnd[i+1] + dists[i];
		}
		valueEnd[i] = 2*heights[i] - distEnd[i];
	}
	valueEnd[2*N] = -Infty;


	make_tree();

	for(int q = 0; q < M; q++){
		int a, b, l, r;
		scanf("%d%d", &a, &b);
		a--; b--;

		if(b < a){
			l = b+1;
			r = a-1;
		} else {
			l = b+1;
			r = a-1+N;
		}

		PNode result = get_result(l, r);

		vector<int> possible;
	   
		possible.push_back(result.max1start);
		possible.push_back(result.max2start);
		possible.push_back(result.max1end);
		possible.push_back(result.max2end);
	
	//	{result.max1start, result.max1end,
	//		result.max2start, result.max2end};

		LL total_res = 0;

		for(int u: possible){
			for(int v: possible){
//				printf("%d %d\n", u, v);
				total_res = max(total_res, get_res(u, v));
			}
		}

		printf("%I64d\n", total_res);
	}
}