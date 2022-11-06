#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	int a[30];
	f(i, 30)a[i] = 0;
	vector<int>b;
	int k;
	int n;
	bool v = false;
	b.push_back(31);
	b.push_back(28);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(28);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(28);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(29);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(28);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(28);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(28);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);
	b.push_back(30);
	b.push_back(31);

	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i]);
	}

	f(i, 84-n){
		k = 0;
		f(j, n){
			if (a[j] == b[i + j])k++;
			else break;
		}
		if (k == n){
			v = true;
			break;
		}
	}

	if (v)printf("YES\n");
	else printf("NO\n");

	return 0;
}