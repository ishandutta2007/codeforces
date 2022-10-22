#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n, m, k;
vector<P> vecA, vecB, vecAB, vecO;
vector<llint> sumA, sumB, sumAB, sumO;
BIT bit(10005), bit2(10005);

void make(vector<P> vec, vector<llint> &sum)
{
	sum.push_back(0);
	llint s = 0;
	for(int i = 0; i < vec.size(); i++){
		s += vec[i].first;
		sum.push_back(s);
	}
}

void add(llint x)
{
	bit.add(x, 1);
	bit2.add(x, x);
}
void del(llint x)
{
	bit.add(x, -1);
	bit2.add(x, -x);
}
llint query(llint x)
{
	if(x == 0) return 0;
	
	llint ub = 10000, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(bit.query(mid) >= x) ub = mid;
		else lb = mid;
	}
	llint ret = bit2.query(ub-1), rem = x - bit.query(ub-1);
	ret += ub * rem;
	return ret;
}
llint getsize()
{
	return bit.query(10000);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	llint t, a, b;
	for(int i = 1; i <= n; i++){
		cin >> t >> a >> b;
		if(a == 0){
			if(b == 0) vecO.push_back(P(t, i));
			else vecB.push_back(P(t, i));
		}
		else{
			if(b == 0) vecA.push_back(P(t, i));
			else vecAB.push_back(P(t, i));
		}
	}
	sort(vecA.begin(), vecA.end());
	sort(vecB.begin(), vecB.end());
	sort(vecAB.begin(), vecAB.end());
	sort(vecO.begin(), vecO.end());
	
	make(vecA, sumA);
	make(vecB, sumB);
	make(vecAB, sumAB);
	make(vecO, sumO);
	
	llint ans = inf, ans_i;
	for(int i = 0; i < vecAB.size(); i++) add(vecAB[i].first);
	for(int i = k; i < vecA.size(); i++) add(vecA[i].first);
	for(int i = k; i < vecB.size(); i++) add(vecB[i].first);
	for(int i = 0; i < vecO.size(); i++) add(vecO[i].first);
	
	llint N = min(k, (llint)vecAB.size());
	for(int i = 0; i <= N; i++){
		llint tmp = sumAB[i];
		llint rem = m - (i+2*(k-i));
		if(vecA.size() >= k-i && vecB.size() >= k-i && rem >= 0 && getsize() >= rem){
			tmp += sumA[k-i] + sumB[k-i] + query(rem);
			if(ans > tmp){
				ans = tmp;
				ans_i = i;
			}
		}
		if(k-i-1 >= 0 && k-i-1 < vecA.size()) add(vecA[k-i-1].first);
		if(k-i-1 >= 0 && k-i-1 < vecB.size()) add(vecB[k-i-1].first);
		if(i < vecAB.size()) del(vecAB[i].first);
		
		//cout << i << " " << ans << " " << sumS << endl;
	}
	if(ans > inf/2){
		cout << -1 << endl;
		return 0;
	}
	
	vector<llint> avec; vector<P> tmp;
	for(int i = 0; i < vecAB.size(); i++){
		if(i < ans_i) avec.push_back(vecAB[i].second);
		else tmp.push_back(vecAB[i]);
	}
	for(int i = 0; i < vecA.size(); i++){
		if(i < k-ans_i) avec.push_back(vecA[i].second);
		else tmp.push_back(vecA[i]);
	}
	for(int i = 0; i < vecB.size(); i++){
		if(i < k-ans_i) avec.push_back(vecB[i].second);
		else tmp.push_back(vecB[i]);
	}
	for(int i = 0; i < vecO.size(); i++) tmp.push_back(vecO[i]);
	
	sort(tmp.begin(), tmp.end());
	for(int i = 0; i < m - (ans_i+2*(k-ans_i)); i++) avec.push_back(tmp[i].second);
	
	cout << ans << endl;
	for(int i = 0; i < avec.size(); i++) cout << abs(avec[i]) << " ";
	cout << endl;
	
	
	return 0;
}