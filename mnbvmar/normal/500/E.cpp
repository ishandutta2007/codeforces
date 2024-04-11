#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

// segtree
const int MaxSiz = 600000,
	      Base = (1<<18);

int P[MaxSiz];

void add(int l, int r, int v){
	l += Base; r += Base;
	P[l] += v;
	if(l != r) P[r] += v;

	while(l/2 != r/2){
		if(l % 2 == 0) P[l+1] += v;
		if(r % 2 == 1) P[r-1] += v;
		l /= 2; r /= 2;
	}
}

int get(int pos){
	pos += Base;
	int res = 0;

	while(pos){
		res += P[pos];
		pos /= 2;
	}
	return res;
}


////////////////


const int MaxN = 200005,
          MaxQ = 200005;

int N, Q;

int dx[MaxN], dy[MaxN];

struct query {
	int from, to, num, res;
	bool operator<(const query& other) const {
		if(to != other.to) return to < other.to;
		return from < other.from;
	}
};
query queries[MaxQ];

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d%d", &dx[i], &dy[i]);

	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		int f, t;
		scanf("%d%d", &f, &t);
		f--; t--;
		queries[i] = query{f, t, i, 0};
	}
}




void output(){
	vector<int> results(Q);
	for(int i = 0; i < Q; i++)
		results[queries[i].num] = queries[i].res;

	for(int i = 0; i < Q; i++)
		printf("%d\n", results[i]);
}

vector<int> numQueries[MaxN];

int main(){
	input();

	sort(queries, queries+Q);

	for(int i = 0; i < Q; i++){
		numQueries[queries[i].to].push_back(i);
	}

	stack<pair<int,int>> S;

	for(int right = 0; right < N; right++){
		int curX = dx[right], curY = dy[right];
		int toElem = right-1;

		while(!S.empty()){
			if(S.top().second >= curX) break;
			
			int fromElem = S.top().first;
			add(fromElem, toElem, curX - S.top().second);
			toElem = fromElem-1;

			S.pop();
		}

		while(!S.empty()){
			if(S.top().second > curX + curY) break;
			toElem = S.top().first - 1;
			S.pop();
		}

		S.push(make_pair(toElem+1, curX + curY));

		for(int qu: numQueries[right]){
			queries[qu].res = get(queries[qu].from);
		}
	}

	output();
}