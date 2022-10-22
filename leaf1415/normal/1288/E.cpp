#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdio>
#define mod 1000000007

using namespace std;
typedef pair<int, int> P;

int cnt[300005], kind;

struct Mo{
	typedef pair<P, P> Query;
	int B;
	vector<int> vec;
	vector<Query> qvec;
	vector<P> avec;
	int qid;
	
	Mo(){
		init();
	}
	init(){
		vec.clear();
		qvec.clear();
		avec.clear();
		qid = 0;
	}
	void setArray(vector<int> &src){
		vec = src;
		B = sqrt((int)src.size());
	}
	int addQuery(int l, int r)
	{
		qvec.push_back(Query(P(l/B, r), P(l, qid)));
		return qid++;
	}
	void calc()
	{
		if(qvec.size() == 0) return;
		sort(qvec.begin(), qvec.end());
		
		int l = qvec[0].second.first, r = qvec[0].first.second;
		for(int i = l; i <= r; i++) add(vec[i]);
		avec.push_back(P(qvec[0].second.second, get()));
		
		for(int i = 1; i < qvec.size(); i++){
			int nl = qvec[i].second.first, nr = qvec[i].first.second;
			while(l < nl) erase(vec[l]), l++;
			while(l > nl) l--, add(vec[l]);
			while(r < nr) r++, add(vec[r]);
			while(r > nr) erase(vec[r]), r--;
			int qid = qvec[i].second.second;
			avec.push_back(P(qid, get()));
		}
		sort(avec.begin(), avec.end());
	}
	int getAnswer(int qid)
	{
		return avec[qid].second;
	}
	
	void add(int x)
	{
		if(cnt[x] == 0) kind++;
		cnt[x]++;
	}
	void erase(int x)
	{
		if(cnt[x] == 1) kind--;
		cnt[x]--;
	}
	int get()
	{
		return kind;
	}
};

int n, m;
vector<int> vec, pvec[300005];
int a[300005];
bool used[300005];
int lans[300005], rans[300005];
vector<int> idvec[300005];
Mo mo;

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) scanf("%d", &a[i]), used[a[i]] = true;
	
	/*if(n == 1){
		printf("1 1\n");
		return 0;
	}*/
	
	for(int i = 1; i <= n; i++){
		if(used[i]) lans[i] = 1;
		else lans[i] = i;
	}
	
	for(int i = m; i >= 1; i--) vec.push_back(a[i]);
	for(int i = 1; i <= n; i++) vec.push_back(i);
	for(int i = 1; i <= n; i++) pvec[i].push_back(-1);
	for(int i = 0; i < vec.size(); i++) pvec[vec[i]].push_back(i);
	
	mo.setArray(vec);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < pvec[i].size(); j++){
			int l = pvec[i][j-1]+1, r = pvec[i][j]-1;
			if(l > r) continue;
			idvec[i].push_back(mo.addQuery(l, r));
		}
	}
	mo.calc();
	
	for(int i = 1; i <= n; i++){
		int mx = 1, cnt = 0;
		for(int j = 1; j < pvec[i].size(); j++){
			int l = pvec[i][j-1]+1, r = pvec[i][j]-1;
			if(l > r) continue;
			int qid = idvec[i][cnt++];
			mx = max(mx, mo.getAnswer(qid)+1);
		}
		rans[i] = mx;
	}
	
	for(int i = 1; i <= n; i++) printf("%d %d\n", lans[i], rans[i]);

	return 0;
}