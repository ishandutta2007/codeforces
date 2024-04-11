#include<bits/stdc++.h>
 
using namespace std;
 
using int64 = long long;
using vi = vector< int >;
const int INF = 1 << 30;
const int mod = 1e9 + 7;
 
int N, R, V[100000];
vector< int > g[100000];
int in[100000], out[100000], dep[100000], ptr;
 
class SparseTable
{
	public:
  	std::vector<int*> table;
  	std::vector<int> table_data;
  	SparseTable(){}
  	SparseTable(vector< int >& A)
  	{
    	int N = A.size();
    	size_t K_size = log(N) + 1;
    	table = std::vector<int*>(K_size);
    	table_data = std::vector<int>((N + 1) * K_size - (1 << K_size) + 1);
    	for (int k = 0, allocated = 0; k < K_size; ++k)
    	{
      		table[k] = table_data.data() + allocated;
      		allocated += N + 1 - (1 << k);
    	}
    	for (int i = 0; i < N; ++i)
    	{
      		table[0][i] = A[i];
    	}
    	for (int k = 1; (1 << k) <= N; ++k)
    	{
      		for (int i = 0; i + (1 << k) <= N; ++i)
      		{
        		table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
      		}
    	}
  	}
  	inline int getMin(int s, int t)
  	{
    	int range = t - s;
    	int k = log(range);
    	int value1 = table[k][s];
    	if (value1 == 0)
      		return 0; 
    	int value2 = table[k][t - (1 << k)];
    	return min(value1, value2);
  	}
  	inline static int log(int n)
  	{
    	return std::__lg(n);
  	}
};
 
 
struct SegmentTreeFractionalCascading
{
  	vector< vector< pair< int, int > > > seg;
  	vector< SparseTable > rmqs;
  	vector< vector< int > > LL, RR;
  	int sz;
  	SegmentTreeFractionalCascading(vector< pair< int, int > > &array, vector< int > &array2)
  	{
    	sz = 1;
    	while(sz < array.size()) sz <<= 1;
    	seg.resize(2 * sz - 1);
    	LL.resize(2 * sz - 1);
    	RR.resize(2 * sz - 1);
    	rmqs.resize(2 * sz - 1);
    	for(int k = 0; k < array.size(); k++) 
		{
      		seg[k + sz - 1].emplace_back(array[k]);
      		vector< int > vs(1);
      		vs[0] = array2[array[k].second];
      		rmqs[k + sz - 1] = SparseTable(vs);
    	}
    	for(int k = sz - 2; k >= 0; k--) 
		{
      		seg[k].resize(seg[2 * k + 1].size() + seg[2 * k + 2].size());
      		LL[k].resize(seg[k].size() + 1);
      		RR[k].resize(seg[k].size() + 1);
      		merge(begin(seg[2 * k + 1]), end(seg[2 * k + 1]), begin(seg[2 * k + 2]), end(seg[2 * k + 2]), begin(seg[k])); 
      		vector< int > vs(seg[k].size());
      		for(int i = 0; i < seg[k].size(); i++) 
			{
        		vs[i] = array2[seg[k][i].second];
      		}
      		rmqs[k] = SparseTable(vs);
      		int tail1 = 0, tail2 = 0;
      		for(int i = 0; i < seg[k].size(); i++) 
			{
        		while(tail1 < seg[2 * k + 1].size() && seg[2 * k + 1][tail1] < seg[k][i]) ++tail1;
        		while(tail2 < seg[2 * k + 2].size() && seg[2 * k + 2][tail2] < seg[k][i]) ++tail2;
        		LL[k][i] = tail1, RR[k][i] = tail2;
      		}
      		LL[k][seg[k].size()] = (int) seg[2 * k + 1].size();
      		RR[k][seg[k].size()] = (int) seg[2 * k + 2].size();
    	}
  	}
	inline int query(int a, int b, int lower, int upper, int k, int l, int r)
  	{
    	if(lower >= upper || a >= r || b <= l) 
		{
      		return (1 << 30);
    	} 
		else if(a <= l && r <= b) 
		{
     		return (rmqs[k].getMin(lower, upper));
    	} 
		else 
		{
      		return (min(query(a, b, LL[k][lower], LL[k][upper], 2 * k + 1, l, (l + r) >> 1), query(a, b, RR[k][lower], RR[k][upper], 2 * k + 2, (l + r) >> 1, r)));
    	}
  	}
  	int query(int a, int b, int l, int r)
  	{
    	l = lower_bound(begin(seg[0]), end(seg[0]), make_pair(l, -111)) - begin(seg[0]);
    	r = lower_bound(begin(seg[0]), end(seg[0]), make_pair(r, -111)) - begin(seg[0]);
    	return (query(a, b, l, r, 0, 0, sz));
  	}
};
 
void dfs(int idx, int depth, int par)
{
  	in[idx] = ptr++;
  	dep[idx] = depth;
  	for(auto &to : g[idx]) 
	{
    	if(to == par) continue;
    	dfs(to, depth + 1, idx);
  	}
  	out[idx] = ptr;
}
 
int main()
{
  	scanf("%d %d", &N, &R);
  	--R;
  	for(int i = 0; i < N; i++) 
	{
   		scanf("%d", &V[i]);
  	}
  	for(int i = 0; i < N - 1; i++) 
	{
    	int a, b;
    	scanf("%d %d", &a, &b);
    	--a, --b;
    	g[a].emplace_back(b);
    	g[b].emplace_back(a);
  	}
  	dfs(R, 0, -1);
  	vector< pair< int, int > > vs(N);
  	vector< int > us(N);
  	for(int i = 0; i < N; i++) 
	{
    	vs[in[i]] = {dep[i], i};
    	us[i] = V[i];
  	}
  	SegmentTreeFractionalCascading seg(vs, us);
 	int M;
  	scanf("%d", &M);
  	int last = 0;
  	for(int i = 0; i < M; i++) {
    	int P, Q;
    	scanf("%d %d", &P, &Q);
    	int X = (P + last) % N;
    	int K = (Q + last) % N;
    	printf("%d\n", last = seg.query(in[X], out[X], dep[X], dep[X] + K + 1));
  	}
}