#include <iostream>
#define llint long long

using namespace std;

llint n;
llint x[100005], y[100005];
bool used[100005];
bool cover[100005][3];

bool check(llint x1, llint y1, llint x2, llint y2, llint x, llint y)
{
	if(x1 != x2){
		llint t = (y2-y1)*x + y1*(x2-x1) - (y2-y1)*x1;
		if(t % (x2-x1) == 0 && t / (x2-x1) == y) return true;
		return false;
	}
	if(x1 == x2){
		return x1 == x;
	}
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	
	if(n < 3){
		cout << "YES" << endl;
		return 0;
	}
	
	if(check(x[0], y[0], x[1], y[1], x[2], y[2])){
		for(int i = 0; i < n; i++){
			used[i] = check(x[0], y[0], x[1], y[1], x[i], y[i]);
		}
		llint cnt = 0, px, py, qx, qy;
		for(int i = 0; i < n; i++){
			if(used[i]) continue;
			if(cnt == 0){
				px = x[i], py = y[i];
				cnt++;
			}
			else if(cnt == 1){
				qx = x[i], qy = y[i];
				cnt++;
			}
			else if(cnt >= 2) break;
		}
		if(cnt < 2){
			cout << "YES" << endl;
			return 0;
		}
		for(int i = 0; i < n; i++){
			used[i] |= check(px, py, qx, qy, x[i], y[i]);
		}
		for(int i = 0; i < n; i++){
			if(!used[i]){
				cout << "NO" << endl;
				return 0;
			}
		}
		cout << "YES" << endl;
		return 0;
	}
	else{
		{
			for(int i = 0; i < n; i++){
				used[i] = check(x[0], y[0], x[1], y[1], x[i], y[i]);
			}
			llint cnt = 0, px, py, qx, qy;
			for(int i = 0; i < n; i++){
				if(used[i]) continue;
				if(cnt == 0){
					px = x[i], py = y[i];
					cnt++;
				}
				else if(cnt == 1){
					qx = x[i], qy = y[i];
					cnt++;
				}
				else if(cnt >= 2) break;
			}
			if(cnt < 2){
				cout << "YES" << endl;
				return 0;
			}
			for(int i = 0; i < n; i++){
				used[i] |= check(px, py, qx, qy, x[i], y[i]);
			}
			bool ans = true;
			for(int i = 0; i < n; i++){
				if(!used[i]){
					ans = false;
					break;
				}
			}
			if(ans){
				cout << "YES" << endl;
				return 0;
			}
		}
		
		{
			for(int i = 0; i < n; i++){
				used[i] = check(x[0], y[0], x[2], y[2], x[i], y[i]);
			}
			llint cnt = 0, px, py, qx, qy;
			for(int i = 0; i < n; i++){
				if(used[i]) continue;
				if(cnt == 0){
					px = x[i], py = y[i];
					cnt++;
				}
				else if(cnt == 1){
					qx = x[i], qy = y[i];
					cnt++;
				}
				else if(cnt >= 2) break;
			}
			if(cnt < 2){
				cout << "YES" << endl;
				return 0;
			}
			for(int i = 0; i < n; i++){
				used[i] |= check(px, py, qx, qy, x[i], y[i]);
			}
			bool ans = true;
			for(int i = 0; i < n; i++){
				if(!used[i]){
					ans = false;
					break;
				}
			}
			if(ans){
				cout << "YES" << endl;
				return 0;
			}
		}
		
		{
			for(int i = 0; i < n; i++){
				used[i] = check(x[1], y[1], x[2], y[2], x[i], y[i]);
			}
			llint cnt = 0, px, py, qx, qy;
			for(int i = 0; i < n; i++){
				if(used[i]) continue;
				if(cnt == 0){
					px = x[i], py = y[i];
					cnt++;
				}
				else if(cnt == 1){
					qx = x[i], qy = y[i];
					cnt++;
				}
				else if(cnt >= 2) break;
			}
			if(cnt < 2){
				cout << "YES" << endl;
				return 0;
			}
			for(int i = 0; i < n; i++){
				used[i] |= check(px, py, qx, qy, x[i], y[i]);
			}
			bool ans = true;
			for(int i = 0; i < n; i++){
				if(!used[i]){
					ans = false;
					break;
				}
			}
			if(ans){
				cout << "YES" << endl;
				return 0;
			}
		}
		
		cout << "NO" << endl;
		return 0;
	}
	
	return 0;
}