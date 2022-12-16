#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 1e4;
int n,k,p;

string a,temp,ans;
struct node{
	int d,l;
}b[maxn];

bool cmp1(node x, node y){
	if(abs(x.d - p) == abs(y.d - p)){
		if(x.d == y.d) {
			if(x.d >= p) return x.l < y.l;
			else return x.l > y.l;
		}
		return x.d > y.d;
	}
	return abs(x.d - p) < abs(y.d - p);
}

int main(){
	scanf("%d%d", &n, &k);
	cin >> a;
	int mc = 1e9;
	for(p = 0; p <= 9; ++p){
		for(int i = 0; i < (int)a.size(); ++i)
			b[i] = (node){a[i] - '0', i};
		sort(b, b + n, cmp1);
		
		temp = a;
		int co = 0;
		for(int i = 0; i < k; ++i)
			co += abs(b[i].d - p), temp[b[i].l] = p + '0';
		
		if((co == mc && ans > temp) || co < mc)
			mc = co, ans = temp;
	}
	
	printf("%d\n", mc);
	cout << ans;
	
	return 0;
}