
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector< vector<int> > a(5005);
	int n, x;

	scanf("%d", &n);
	for(int i = 1; i <= 2*n; i++){
		scanf("%d", &x);
		a[x].push_back(i);
	}

	bool f = true;
	for(int i = 1; i <= 5000; i++)
		if( a[i].size() % 2 ){
			f = false;
			break;
		}

	if(f)
		for(int i = 1; i <= 5000; i++)
			for(int j = 0; j < a[i].size(); j+=2)
				printf("%d %d\n", a[i][j], a[i][j+1] );
	else
		printf("-1\n");
	return 0;
}