#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct m{
	int a, b, c;
	m(int a, int b, int c) : a(a), b(b), c(c){}
};
vector<m> ans;
vector<int> a;
void flip(int x, int y, int z){
	assert(x >=0 && y >= 0 && z >= 0);
	assert(x+z == y+y);
	a[x] ^= 1;
	a[y] ^= 1;
	a[z] ^= 1;
	ans.push_back(m(x,y,z));
	/*for(int v : a){
		cerr << v << " ";
	}
	cerr << endl;*/
}
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = n-1; i >= 0; i--){
		if(i < 2) continue;
		if(a[i] == 0) continue;
		if(i < 8){
			flip(i-2, i-1, i);
		} else if(a[i-2] && a[i-1]){
			flip(i-2, i-1, i);
		} else if(a[i-2]){
			flip(i-4, i-2, i);			
		} else if(!a[i-2] && !a[i-1]){
			flip(i-6, i-3, i);
		} else if(i < 12){
			flip(i-2, i-1, i);
		} else if(a[i-1] && a[i-3] && a[i-4] && a[i-5]){
			flip(i-8, i-4, i);
			flip(i-5, i-3, i-1);
		} else if(a[i-1]){
			int c1 = i-6;
			int c2 = i-6;
			for(int j = i-5; j <= i-3; j++){
				if(a[j]){
					swap(c1, c2);
					c1 = j;
				}
			}
			flip(c1*2-(i-1), c1, i-1);
			flip(c1*2-i, c1, i);
		}
	}
	if(a[0] == 0 && a[1] == 0 && a[2] == 0){
		cout << "YES" << '\n';
		cout << ans.size() << '\n';
		for(m x : ans){
			cout << x.a + 1 << " " << x.b+1 << " " << x.c + 1 << '\n';
		}
	} else if(n < 7){
		cout << "NO" << endl;
	} else if(n == 7 && a[1]){ 
		cout << "NO" << endl;
	} else {
		if(a[0]){
			flip(0,3,6);
			flip(3,4,5);
			flip(4,5,6);
		}
		if(a[1]){
			flip(1,4,7);
			flip(4,5,6);
			flip(5,6,7);
		}
		cout << "YES" << '\n';
		cout << ans.size() << '\n';
		for(m x : ans){
			cout << x.a + 1 << " " << x.b+1 << " " << x.c + 1 << '\n';
		}
	}
	assert(ans.size() <= n + 12);
}


// 001