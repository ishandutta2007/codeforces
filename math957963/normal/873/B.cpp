#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int main(void){
	char a[100010];
	vector<int>b[200001];
	int k;
	int n;
	int s;
	int x;


	scanf("%d", &n);

	scanf("%s", a);
	s = 0;
	b[100000].push_back(0);
	for (int i = 0; i < n; i++){
		if (a[i] == '0')s++;
		if (a[i] == '1')s--;
		b[s + 100000].push_back(i+1);
	}
	s =0;
	for (int i = 0; i < 200001; i++){
		if (b[i].size()>1){
			x = b[i][b[i].size() - 1] - b[i][0];
				if (x>s)s = x;
		}
	}
	printf("%d", s);

	return 0;
}