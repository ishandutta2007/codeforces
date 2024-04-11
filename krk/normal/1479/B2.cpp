#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
vector <int> inds[Maxn];
int cur[2];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		inds[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (a[i] == cur[0] || a[i] == cur[1]) ;
		else {
			res++;
			int ind1 = upper_bound(inds[cur[0]].begin(), inds[cur[0]].end(), i) - inds[cur[0]].begin();
			if (ind1 == inds[cur[0]].size()) ind1 = n + 1;
			else ind1 = inds[cur[0]][ind1];
			int ind2 = upper_bound(inds[cur[1]].begin(), inds[cur[1]].end(), i) - inds[cur[1]].begin();
			if (ind2 == inds[cur[1]].size()) ind2 = n + 1;
			else ind2 = inds[cur[1]][ind2];
			if (ind1 < ind2) cur[1] = a[i];
			else cur[0] = a[i]; 
		}
	printf("%d\n", res);
    return 0;
}