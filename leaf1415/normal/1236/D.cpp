#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint h, w, k;
vector<llint> rvec[100005], cvec[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> k;
	llint r, c;
	for(int i = 1; i <= k; i++){
		cin >> r >> c;
		rvec[r].push_back(c);
		cvec[c].push_back(r);
	}
	for(int i = 1; i <= h; i++){
		rvec[i].push_back(0);
		rvec[i].push_back(w+1);
	}
	for(int i = 1; i <= w; i++){
		cvec[i].push_back(0);
		cvec[i].push_back(h+1);
	}
	for(int i = 1; i <= h; i++) sort(rvec[i].begin(), rvec[i].end());
	for(int i = 1; i <= w; i++) sort(cvec[i].begin(), cvec[i].end());
	
	r = c = 1;
	llint cnt = 1, nr, nc, d = 0;
	llint r_lb = 1, r_ub = h, c_lb = 1, c_ub = w; bool flag = true, first = true;;
	while(flag){
		//cout << r << " " << c << " " << d << endl;
		nr = r, nc = c;
		if(d == 0){
			nc = *lower_bound(rvec[r].begin(), rvec[r].end(), c)-1;
			if(nc > c_ub){
				nc = c_ub;
				//flag = false;
			}
			r_lb = r+1;
		}
		
		if(d == 1){
			nr = *lower_bound(cvec[c].begin(), cvec[c].end(), r)-1;
			if(nr > r_ub){
				nr = r_ub;
				//flag = false;
			}
			c_ub = c-1;
		}
		if(d == 2){
			nc = *(lower_bound(rvec[r].begin(), rvec[r].end(), c)-1) + 1;
			if(nc < c_lb){
				nc = c_lb;
				//flag = false;
			}
			r_ub = r-1;
		}
		if(d == 3){
			nr = *(lower_bound(cvec[c].begin(), cvec[c].end(), r)-1) + 1;
			if(nr < r_lb){
				nr = r_lb;
				//flag = false;
			}
			c_lb = c+1;
		}
		d = (d+1)%4;
		cnt += abs(nc-c) + abs(nr-r);
		if(!first && r == nr && c == nc) flag = false;
		r = nr, c = nc;
		first = false;
	}
	if(cnt < h*w-k) cout << "No" << endl;
	else cout << "Yes" << endl;
	
	return 0;
}