# include <iostream>
# include <cstdio>
# include <set>
using namespace std;

set<int> s;
int a[100010];

int main()
{
    int n, m;
	scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=n; i; i--) {
        s.insert(a[i]);
        a[i]=s.size();
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}