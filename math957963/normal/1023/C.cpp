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
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
	char a[N + 1];
	int b[N + 1];
	bool c[N + 1];
	f(i, N + 1){
		a[i] = 0;
		b[i] = 0;
		c[i] = true;
	}
	stack<int>st;
	vector<pair<int, int> >p;
	int n, k;
	int x, y, z;

	scanf("%d %d", &n, &k);
	scanf("%s", a);
	x = 0;
	f(i, n){
		if (a[i] == '('){
			x++;
			st.push(i);
			p.push_back(make_pair(-x, i) );
		}
		else{
			x--;
			y = st.top();
			st.pop();
			b[i] = y;
			b[y] = i;
		}
	}
	z = n - k;
	z = z / 2;
	sort(p.begin(), p.end());
	f(i, z){
		c[p[i].second] = false;
		c[b[p[i].second]] = false;
	}
	f(i, n){
		if (c[i])printf("%c", a[i]);
	}
	printf("\n");
	return 0;
}