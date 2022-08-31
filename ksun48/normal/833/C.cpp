#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[18];
LL ans = 0;
LL l, r;
LL p10[18];

void test(){
	int used[18];
	for(int i = 0; i < 18; i++){
		used[i] = 0;
	}
	if(1){
		LL num = 0;
		LL num2 = 0;
		for(int i = 0; i < 18; i++){
			num *= 10;
			num += a[i];
			num2 *= 10;
			num2 += a[17-i];
		}
		if(num >= l && num <= r){
			//cout << num << endl;
			ans++;
			return;
		}
		if(num2 >= l && num2 <= r){
			ans++;
			return;
		}
	}

	LL startnum = 0;
	for(int i = 0; i < 18; i++){
		LL f = l/p10[17-i];
		LL g = r/p10[17-i];
		/*if(i > 15){
			cout << startnum << " " << f << " " << g << " ";
			for(int c = 0; c < 18; c++){
				if(!used[c]){
					cout << a[c];
				}
			}
			cout << endl;
		}*/
		if(f == g){
			int j = -1;
			for(int c = 0; c < 18; c++){
				if(used[c]) continue;
				if((startnum * 10 + a[c]) == f){
					j = c;
					break;
				}
			}
			if(j == -1) return;
			used[j] = 1;
			startnum = f;
		} else {
			int j1 = -1;
			for(int c = 0; c < 18; c++){
				if(used[c]) continue;
				if((startnum * 10 + a[c]) <= f){
					continue;
				}
				j1 = c;
				break;
			}
			int j2 = -1;
			for(int c = 0; c < 18; c++){
				if(used[17-c]) continue;
				if((startnum * 10 + a[17-c]) >= g){
					continue;
				}
				j2 = 17-c;
				break;
			}
			if(j1 != -1){
				LL num1 = startnum * 10 + a[j1];
				used[j1] = 1;
				for(int c = 0; c < 18; c++){
					if(used[c]) continue;
					num1 *= 10;
					num1 += a[c];
				}
				used[j1] = 0;
				//cout << num1 << endl;
				if(num1 >= l && num1 <= r){
					//cout << num1 << endl;
					ans++;
					return;
				}
			}

			if(j2 != -1){
				LL num2 = startnum * 10 + a[j2];
				used[j2] = 1;
				for(int c = 0; c < 18; c++){
					if(used[17-c]) continue;
					num2 *= 10;
					num2 += a[17-c];
				}
				used[j2] = 0;
				//cout << num2 << endl;
				if(num2 >= l && num2 <= r){
					//cout << num2 << endl;
					ans++;
					return;
				}
			}
			return;
		}
	}
	if(startnum >= l && startnum <= r){
		//cout << startnum << endl;
		ans++;
		return;
	}
}

void flip(int k, int n, int cur){
	if(k == n){
		test();
		return;
	}
	for(int j = cur; j < 10; j++){
		a[k] = j;
		flip(k+1,n,j);
	}
}
int main(){
	p10[0] = 1;
	for(int i = 1; i < 18; i++){
		p10[i] = p10[i-1] * 10;
	}

	cin >> l >> r;
	LL f1 = 1000000000000000000LL;
	if(l == f1 && r == f1){
		cout << 1 << endl;
		return 0;
	}
	if(r == f1){
		r--;
		//cout << "here" << endl;
		LL f = 1e17;
		if(l > f) ans++;
	}
	flip(0,18,0);
	cout << ans << endl;
}