#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000

vector<int>prim;

void prim_make(int k){
	if (k >= 2)prim.push_back(2);
	if (k >= 3)prim.push_back(3);
	if (k >= 5)prim.push_back(5);
	int x = 7;
	bool v;
	while (x <= k){
		v = true;
		for (int i = 2; prim[i] * prim[i] <= x; i++){
			if (x%prim[i] == 0){
				v = false;
				break;
			}
		}
		if (v)prim.push_back(x);
		if (x % 6 == 1)x += 4;
		else x += 2;
	}
	return;
}


int gcd(int x, int y){
	if (y < x)swap(x, y);
	if (x == 0)return y;
	else return gcd(y%x, x);
}





int main(){
	vector<int>a;
	int n, x;
	int ans;
	map<int, int>primv;
	set<int>s;
	ans = 0;
	prim_make(4000);
	scanf("%d", &n);
	f(i, n){
		scanf("%d", &x);
		a.push_back(x);
		ans = gcd(ans, x);
	}
	
	f(i, n){
		a[i] = a[i] / ans;
	}
	f(i, n){
		f(j, prim.size()){
			if (a[i] % prim[j] == 0){
				if (s.count(prim[j]) == 0){
					primv[prim[j]] = 1;
					s.insert(prim[j]);
				}
				else{
					primv[prim[j]]++;
				}
				while (a[i] % prim[j] == 0)a[i] = (a[i] / prim[j]);
				if (a[i] == 1)break;
			}
		}
		if (a[i] != 1){
			if (s.count(a[i]) == 0){
				primv[a[i]] = 1;
				s.insert(a[i]);
			}
			else{
				primv[a[i]]++;
			}
		}
	}
	if (s.size() == 0){
		printf("-1\n");
		return 0;
	}
	auto itr = s.begin();
	ans = 0;
	while (itr != s.end()){
		ans = max(ans, primv[*itr]);
		itr++;
	}	
	
	printf("%d\n", n-ans);


	return 0;
}