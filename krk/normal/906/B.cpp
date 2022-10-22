#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

int n, m;
vector <vector <int> > B;
vector <vector <int> > R;

int main()
{
	scanf("%d %d", &n, &m);
	if (n == 1 && m == 1) {
		printf("YES\n");
		printf("1\n");
	} else if (n == 3 && m == 3) {
		printf("YES\n");
		printf("6 1 8\n");
		printf("7 5 3\n");
		printf("2 9 4\n");
	} else if (max(n, m) <= 3) printf("NO\n");
		   else {
		   		printf("YES\n");
		   		B.resize(n);
		   		for (int i = 0; i < n; i++) {
		   			B[i].resize(m);
		   			for (int j = 0; j < m; j++)
		   				B[i][j] = i * m + j + 1;
		   		}
		   		R = B;
		   		if (n <= m) {
		   			for (int i = 0; i < n; i++) {
		   				int cur = 0;
		   				for (int j = 1; j < m; j += 2)
		   					R[i][cur++] = B[i][j];
		   				for (int j = 0; j < m; j += 2)
		   					R[i][cur++] = B[i][j];
		   				if (i % 2 == 1) 
		   					if (m % 2 == 0)
		   						for (int j = 0; j < m - 1 - j; j++)
		   							swap(R[i][j], R[i][m - 1 - j]);
		   					else {
		   						int lst = R[i][m - 1];
		   						for (int j = m - 2; j >= 0; j--)
		   							R[i][j + 1] = R[i][j];
		   						R[i][0] = lst;
		   					}
		   			}
		   		} else {
		   			for (int j = 0; j < m; j++) {
		   				int cur = 0;
		   				for (int i = 1; i < n; i += 2)
		   					R[cur++][j] = B[i][j];
		   				for (int i = 0; i < n; i += 2)
		   					R[cur++][j] = B[i][j];
		   				if (j % 2 == 1)
		   					if (n % 2 == 0)
		   						for (int i = 0; i < n - 1 - i; i++)
		   							swap(R[i][j], R[n - 1 - i][j]);
		   					else {
		   						int lst = R[n - 1][j];
		   						for (int i = n - 2; i >= 0; i--)
		   							R[i + 1][j] = R[i][j];
		   						R[0][j] = lst;
		   					}
		   			}
		   		}
		   		for (int i = 0; i < n; i++)
		   			for (int j = 0; j < m; j++)
		   				printf("%d%c", R[i][j], j + 1 < m? ' ': '\n');
		   }
	return 0;
}