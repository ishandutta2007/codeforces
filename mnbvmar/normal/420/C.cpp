#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define MP make_pair

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int,int> VII;
typedef pair<int,int> PII;
const LD Eps = 1e-8;

int n, p;
int num[300005];
map<PII, int> M;

void input(){
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		num[a]++; num[b]++;
		
		if(a > b) swap(a,b);
		M[{a,b}]++;
	}
}

int main(){
	input();
	
	LL cnt = 0;
	for(auto P: M){
		int occur = P.second;
		PII pair = P.first;
		
		int sum = num[pair.first] + num[pair.second];
		if(sum >= p && sum - occur < p)
			cnt--;
	}
	
	
	
	sort(num+1, num+n+1);
	
	num[0] = -1010101010;
	int R = n;
	for(int L = 1; L <= n; L++){
		while(num[R] + num[L] >= p) R--;
		if(R >= L)
			cnt += (n-R);
		else
			cnt += (n-L);
	}
	
	printf("%I64d\n", cnt);
}