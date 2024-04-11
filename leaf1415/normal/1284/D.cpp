#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint n;
llint l[100005], r[100005], l2[100005], r2[100005];
llint num[100005], num2[100005];
vector<E> vec;
set<P> leftS, rightS;

void calc(llint l[], llint r[], llint num[])
{
	vector<llint> lvec, rvec;
	for(int i = 1; i <= n; i++){
		lvec.push_back(l[i]);
		rvec.push_back(r[i]);
	}
	sort(lvec.begin(), lvec.end());
	sort(rvec.begin(), rvec.end());
	for(int i = 1; i <= n; i++){
		num[i] = n-1;
		num[i] -= lvec.end() - upper_bound(lvec.begin(), lvec.end(), r[i]);
		num[i] -= lower_bound(rvec.begin(), rvec.end(), l[i]) - rvec.begin(); 
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> l2[i] >> r2[i];
	if(n == 1){
		cout << "YES" << endl;
		return 0;
	}
	calc(l, r, num);
	calc(l2, r2, num2);
	
	//for(int i = 1; i <= n; i++) cout << num[i] << " "; cout << endl;
	
	for(int i = 1; i <= n; i++){
		if(num[i] != num2[i]){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	for(int i = 1; i <= n; i++){
		vec.push_back(E(l[i], P(i, 1)));
		vec.push_back(E(r[i], P(i, 2)));
	}
	sort(vec.begin(), vec.end());
	
	leftS.insert(P(-inf, 0)), rightS.insert(P(inf, 0));
	for(int i = 0; i < vec.size(); i++){
		llint id = vec[i].second.first;
		if(vec[i].second.second == 2){
			leftS.erase(P(l2[id], id));
			rightS.erase(P(r2[id], id));
		}
		else{
			llint R = rightS.begin()->first, L;
			auto it = leftS.end(); it--;
			L = it->first;
			//cout << L << " " << R << endl;
			if(max(l2[id], L) > min(r2[id], R)){
				cout << "NO" << endl;
				return 0;
			}
			leftS.insert(P(l2[id], id)), rightS.insert(P(r2[id], id));
		}
	}
	cout << "YES" << endl;
	
	return 0;
}