#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)

using namespace std;

const double eps = 1e-9;
const double PI = acos(-1.0);
const int INF = 1e9+7;
const int MAXN = int (2e5+7);

int n, m, sum, a[1007], b[1007];
char c[1007][1007];

int main () { 
   	//freopen("input.in", "r", stdin);
   	//freopen("output.txt", "w", stdout);  

   	scanf("%d%d", &n, &m);
   	for(int i = 0; i < n; i ++) {
   		scanf("%s", c[i]);
   		for(int j = 0; j < m; j ++)
   			if(c[i][j] == '*')
   				a[i] ++;
   		sum += a[i];
   	}
   	for(int i = 0; i < m; i ++) {
   		for(int j = 0; j < n; j ++) {
   			if(c[j][i] == '*')
   				b[i] ++;
   		}
   	}
   	for(int i = 0; i < n; i ++) {
   		for(int j = 0; j < m; j ++) {
   			int res = a[i] + b[j] - (c[i][j] == '*');
   			if(sum == res) {
   				printf("YES\n%d %d", i + 1, j + 1);
   				return 0;
   			}
   		}
   	}
   	cout << "NO";
   	return 0;
}