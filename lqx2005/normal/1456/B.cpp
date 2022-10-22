#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
const int N = 1e5 + 10, Log = 30;
int n, a[N], s[N];

int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = s[i - 1] ^ a[i];
  if(n >= 200) return printf("1\n"), 0;
  int ans = n + 5;
  for(int i = 0; i <= n; i++)
  {
    for(int j = i + 1; j <= n; j++)
    {
      for(int k = j + 1; k <= n; k++)
      {
        if((s[i] ^ s[j]) > (s[j] ^ s[k])) ans = min(ans, j - i - 1 + k - j - 1);
      }
    }
  }
  if(ans >= n + 5) printf("-1\n");
  else printf("%d\n", ans);
	return 0;
}