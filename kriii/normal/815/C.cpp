#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> G[5050];
int N; long long B,C[5050],D[5050]; int X[5050];

vector<long long> mult(vector<long long> &a, vector<long long> &b)
{
	vector<long long> r(a.size() + b.size() - 1, 1e18);
	for (int i=0;i<a.size();i++) for (int j=0;j<b.size();j++) if (r[i+j] > a[i] + b[j]) r[i+j] = a[i] + b[j];
	return std::move(r);
}

pair<vector<long long>, vector<long long> > r(int x)
{
	pair<vector<long long>, vector<long long> > ret;
	vector<long long> &a = ret.first;
	vector<long long> &b = ret.second;
	a.resize(1);
	a[0] = C[x] - D[x];
	b.resize(2);
	b[0] = 0;
	b[1] = C[x];
	for (auto &y : G[x]){
		auto res = r(y);
		a = mult(a,res.first);
		b = mult(b,res.second);
	}
	a.insert(a.begin(),0);
	for (int i=0;i<b.size();i++) a[i] = min(a[i],b[i]);
	return std::move(ret);
}

int main()
{
	scanf ("%d %lld",&N,&B);
	for (int i=1;i<=N;i++){
		scanf ("%lld %lld",&C[i],&D[i]);
		if (i > 1){
			scanf ("%d",&X[i]);
			G[X[i]].push_back(i);
		}
	}

	auto res = r(1).first;
	int mx = 0;
	for (int i=0;i<=N;i++){
		if (res[i] <= B){
			mx = i;
		}
	}
	printf ("%d\n",mx);

	return 0;
}